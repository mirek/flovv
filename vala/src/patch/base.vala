using Gee;
using GLib;

namespace Flovv.Patch {
    public abstract class Base : Object {
        public string? identifier { get; set; default = null; }
        
        private string _patch_type_name = null;
        
        public string patch_type_name {
            get {
                if (_patch_type_name == null) {
                    _patch_type_name = "unknown";
                    if (this is Provider) _patch_type_name = "provider";
                    if (this is Processor) _patch_type_name = "processor";
                    if (this is Consumer) _patch_type_name = "consumer";
                }
                return _patch_type_name;
            }
        }

        public Set<Base> depends_on = new HashSet<Base>();
        public Set<Base> triggers = new HashSet<Base>();
        
        [Description(nick = "Enabled", blurb = "Determines if the patch is enabled")]
        public bool in_enabled { get; set; default = true; }
        
        public void connect_to(string key, Base other, string other_key) {
            this.notify[key].connect((self, property_spec) => {
                Value value = Value(property_spec.value_type);
                self.get_property(property_spec.name, ref value);
                other.set_property(other_key, value);
            });
            triggers.add(other);
            other.depends_on.add(this);
        }

        public void connect_from(string key, Base other, string other_key) {
            other.notify[other_key].connect((other_self, property_spec) => {
                Value value = Value(property_spec.value_type);
                other_self.get_property(property_spec.name, ref value);
                this.set_property(key, value);
            });
            other.triggers.add(this);
            depends_on.add(other);
        }
        
        public bool is_independent() {
            return depends_on.size == 0;
        }

        // public void out_set<T>(string key, T? value) {
        //     _out.set(key, (Object) value);
        // }
        // 
        // public T in_get<T>(string key) {
        //     return (T) _in.get(key);
        // }
        
        public void run_if_enabled() {
            if (in_enabled)
                run();
        }

        public abstract void run();
    }
}
