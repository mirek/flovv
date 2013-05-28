
namespace Flovv.Patch {

    public class Fps : Provider {
        private int64 last = 0;
        private int fps = 0;
        public signal void out_fps(int fps);

        public override void run() {
            int64 now = new DateTime.now_utc().to_unix();
            if (now != last) {
                out_fps(fps);
                fps = 0;
                last = now;
            }
            fps++;
        }
    }
}
