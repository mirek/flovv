using Gee;
using GLib;

namespace Flovv {
    
    public class Visitor {
        
        // Execution path
        public List<string> ordered = new ArrayList<string>();
        
        // Element dependencies
        public Map<string, Set<string>> deps = new HashMap<string, Set<string>>(GLib.str_hash, GLib.str_equal, GLib.direct_equal);
        public Map<string, Set<string>> ideps = new HashMap<string, Set<string>>(GLib.str_hash, GLib.str_equal, GLib.direct_equal);

        public delegate void NodeIteratorCallback(string e);

        public void add_node(string e) {
            if (!(e in deps)) {
                deps[e] = new HashSet<string>(GLib.str_hash, GLib.str_equal);
                ideps[e] = new HashSet<string>(GLib.str_hash, GLib.str_equal);
                rebuild();
            } else {
                stderr.printf("Flovv.Visitor.add_node(%%s) -> already added\n");
            }
        }

        public void add_connection(string src, string dst) {
            if (src in deps && dst in deps) {
                deps[dst].add(src);
                ideps[src].add(dst);
                rebuild();
            } else {
                stderr.printf("Flovv.Visitor.add_connection(%%s, %%s) -> not found\n");
            }
        }
        
        public void rebuild(string? e = null, Set<string>? s = null) {
            if (e == null) {
                ordered.clear();
                var s_ = new HashSet<string>(GLib.str_hash, GLib.str_equal);
                foreach (var f in ideps.get_keys())
                    if (ideps[f].size == 0)
                        rebuild(f, s_);
            } else {
                if (!(e in s)) {
                    s.add(e);
                    foreach (var f in deps[e])
                        rebuild(f, s);
                    ordered.add(e);
                }
            }
        }

        public void loop_once(NodeIteratorCallback f) {
            foreach (var e in ordered)
                f(e);
        }
    }
    
}
