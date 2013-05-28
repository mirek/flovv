using Gee;
using GLib;
using Sqlite;

namespace Flovv.Reader {
    
    public class Sqlite3 : Base {
        public Database sqlite = null;
        public int rc = Sqlite.OK;

        // public event reader_patch(string name, Hash<string, Object> settings);
        // public event reader_connect(Patch.Base source, string output, Patch.Base destination, string input);

        public Sqlite3() {
        }

        // public int read_from_file(string path) {
        //     if (Sqlite.OK == open(path)) {
        //         read_patches();
        //         read_connections();
        //     }
        //     return rc;
        // }
        
        // public delegate void PatchCallback(string name, string id, Map<string, string>? settings = null);
        
        // public static HashMap<K, V> new_hash_map_from_keys_and_values(int n, K[] keys, V[] values) {
        //     HashMap<K, V> result = new HashMap<K, V>();
        //     if (int i = 0; i < n; i++)
        //         result[keys[i]] = values[i];
        //     return result;
        // }
        
        public override Map<string, string> get_settings(string? table, string id) {
            var result = new HashMap<string, string>(GLib.str_hash, GLib.str_equal, GLib.str_equal);
            sqlite.exec("select key, value from settings where patch_id = " + id, (n, v, k) => {
                result[v[0]] = v[1];
                return Sqlite.OK;
            });
            stdout.printf("Flovv.reader.get_settings(%s, %s, ", table, id);
            if (result.size > 0) {
                foreach (string key in result.get_keys()) {
                    stdout.printf("\n  %s: %s\n", key, result[key]);
                }
            }
            stdout.printf(")\n");
            // log(debug: "");
            return result;
        }
        
        // public void log(string level, string format)

        public override void foreach_patch(PatchCallback f) {
            sqlite.exec("select id, name, identifier from patches", (n, v, k) => {
                f(v[1], v[2], get_settings(null, v[0]));
                return Sqlite.OK;
            });
        }

        // public delegate void ConnectionCallback(string source, string output, string destination, string input);

        public override void foreach_connection(ConnectionCallback f) {
            sqlite.exec("
                select
                    sp.identifier as source,
                    c.output as output,
                    dp.identifier as destination,
                    c.input as input
                from
                    connections as c
                join
                    patches as sp
                on
                    c.source_patch_id = sp.id
                join
                    patches as dp
                on
                    c.destination_patch_id = dp.id
                ", (n, v, k) => {
                f(v[0], v[1], v[2], v[3]);
                return Sqlite.OK;
            });
        }
        
        public override bool open(string path, out string? errmsg = null) {
            return path.has_suffix(".sql") ? open_sql(path, out errmsg) : open_db(path, out errmsg);
        }

        private bool open_db(string path, out string? errmsg = null) {
            bool result = false;
            if (!(result = (Sqlite.OK == Database.open(path, out sqlite)))) {
                errmsg = "Error opening composition databse file %s.".printf(path);
            }
            return result;
        }
        
        private bool execute(string sql, out string? errmsg = null) {
            return sqlite.exec(sql, null, out errmsg) == Sqlite.OK;
        }

        private bool execute_file(string path, out string? errmsg = null) {
            bool result = false;
            if (FileUtils.test(path, FileTest.IS_REGULAR)) {
                string sql = null;
                try {
                    FileUtils.get_contents(path, out sql);
                    result = execute(sql, out errmsg);
                }
                catch (FileError error) {
                    errmsg = error.message;
                }
            } else {
                errmsg = "Failed executing %s file not found.".printf(path);
            }
            return result;
        }
        
        private static string[] migrations = new string[] { "2012012401" };

        private bool migrate(out string? errmsg = null) {
            bool result = true;
            foreach (string migration in migrations) {
                if (false == (result = execute_file("migrations/%s.sql".printf(migration)))) {
                    errmsg = "%s migration failed.".printf(migration);
                    break;
                }
            }
            return result;
        }

        private bool open_sql(string path, out string? errmsg = null) {
            bool result = false;
            if ((result = (rc = Database.open(":memory:", out sqlite)) == Sqlite.OK)) {
                if ((result = migrate(out errmsg))) {
                    result = execute_file(path, out errmsg);
                }
            }
            return result;
        }
    }
}
