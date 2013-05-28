using Gee;
using GLib;
using Sqlite;

namespace Flovv.Reader {

    public delegate void PatchCallback      (string name, string id, Map<string, string>? settings = null);
    public delegate void ConnectionCallback (string source, string output, string destination, string input);
    
    public abstract class Base : Object {
        
        public abstract bool open(string path, out string? error = null);

        public abstract void foreach_connection(ConnectionCallback f);
        public abstract void foreach_patch(PatchCallback f);
        
        public abstract Map<string, string> get_settings(string? table, string id);
    }
}
