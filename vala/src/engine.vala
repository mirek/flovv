using Gee;
using GL;
using GLFW;

namespace Flovv {
    
    public class Engine : Object {
        
        private bool is_loop_running = true;

        public int width = 512;
        public int height = 512;
        
        public Map<string, Patch.Base> patches = null;
        
        // Registered patch types
        public static Map<string, string> patch_type_names = null;
        
        // Graph node visitor, simple topological order currently.
        public Visitor visitor { get; set; }

        public static void register_patch_types() {
            patch_type_names = new HashMap<string, string>(GLib.str_hash, GLib.str_equal, GLib.str_equal);
            register_patch_type("fps", typeof(Flovv.Patch.Fps));
            register_patch_type("frame", typeof(Flovv.Patch.Frame));
            register_patch_type("mouse", typeof(Flovv.Patch.Mouse));
            register_patch_type("sine", typeof(Flovv.Patch.Sine));
            register_patch_type("multiply", typeof(Flovv.Patch.Multiply));
            register_patch_type("cloud", typeof(Flovv.Patch.Cloud));
            register_patch_type("nbody", typeof(Flovv.Patch.NBody));
        }

        public static void register_patch_type(string key, Type type) {
            patch_type_names[key] = type.name();
        }
        
        public Engine() {
            patches = new HashMap<string, Patch.Base>(GLib.str_hash, GLib.str_equal);
            visitor = new Visitor();
            glfwInit();
        }
        
        public void new_connection(string source_patch_identifier, string output, string destination_patch_identifier, string input) {
            patches[source_patch_identifier].connect_to(output, patches[destination_patch_identifier], input);
            visitor.add_connection(source_patch_identifier, destination_patch_identifier);
        }

        public Patch.Base new_patch(string type_key, string identifier, Map<string, string>? settings = null) {
            Patch.Base? patch = null;
            string? type_name = patch_type_names[type_key];
            if (type_name != null) {
                Type type = Type.from_name(type_name);
                if (type != Type.INVALID) {
                    patch = (Patch.Base?) Object.new(type);
                    if (patch != null) {
                        patch.identifier = identifier;
                        if (settings != null) {
                            foreach (string key in settings.get_keys()) {
                                string? value = settings[key];
                                ParamSpec? param_spec = patch.get_class().find_property(key);
                                if (param_spec != null) {
                                    if (param_spec.value_type.is_a(typeof(double))) {
                                        double double_value = 0.0;
                                        value.scanf("%lf", out double_value);
                                        patch.set_property(key, double_value);
                                        stdout.printf("ok!!!\n");
                                    }
                                    // if (Value.type_compatible(typeof(string), param_spec.value_type)) {
                                    //     stdout.printf("aaa\n");
                                    //     // patch.set_property(key, settings[key]);
                                    // } else if (Value.type_transformable(typeof(string), param_spec.value_type)) {
                                    //     stdout.printf("bbb\n");
                                    // } else {
                                    //     stdout.printf("ccc\n");
                                    // }
                                }
                            }
                        }
                        patches[patch.identifier] = patch;
                        visitor.add_node(patch.identifier);
                    }
                } else {
                    stdout.printf("invalid type for '%s' patch type key and %s patch type name\n", type_key, type_name);
                }
            } else {
                stdout.printf("type not found for '%s' patch type key\n", type_key);
            }
            return patch;
        }

        // public void add(Patch.Base patch) {
        //     patches[patch.identifier] = patch;
        // }

        public bool open(int width = 512, int height = 512) {
            this.width = width;
            this.height = height;
            return glfwOpenWindow(width, height, 0, 0, 0, 0, 0, 0, Mode.WINDOW);
        }
        
        public void terminate() {
            glfwTerminate();
        }

        // For now loops forever
        public void run_loop() {
            while (is_loop_running) {
                glClear(GL_COLOR_BUFFER_BIT);

                // Step through all patches in the order
                // visitor says.
                visitor.loop_once((identifier) => {
                    patches[identifier].run_if_enabled();
                });

                // Swap front and back rendering buffers
                glfwSwapBuffers();
                
                // Check if ESC key was pressed or window was closed
                is_loop_running = !glfwGetKey(Key.ESC) && (bool) glfwGetWindowParam(WindowParam.OPENED);
            }
            terminate();
        }
        
    }
    
}