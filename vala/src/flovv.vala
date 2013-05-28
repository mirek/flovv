using GLib;
using GLFW;
using GL;
using Flovv;

int main(string[] args) {
    string? errmsg = null;
    string me = args[0];
    if (args.length == 2) {
        string path = args[1];
        Engine.register_patch_types();
        Engine engine = new Engine();
        Reader.Base reader = new Reader.Sqlite3();
        if (reader.open(path, out errmsg)) {
            reader.foreach_patch((name, id, settings) => {
                engine.new_patch(name, id, settings);
            });
            reader.foreach_connection((source, output, destination, input) => {
                engine.new_connection(source, output, destination, input);
            });
            engine.open(512, 512);
            engine.run_loop();
        } else {
            if (errmsg != null) {
                stdout.printf("%s\n", errmsg);
            } else {
                stdout.printf("Failed opening '%s' composition.\n", path);
            }
        }
    } else {
        stdout.printf("Usage:\n\t%s composition.[db|sql]\n", me);
    }
    return 0;
}
