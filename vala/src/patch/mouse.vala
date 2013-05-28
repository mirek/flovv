using GLFW;

namespace Flovv.Patch {
    public class Mouse: Provider {
        private int x = 0;
        private int y = 0;
        private int w = 1;
        private int h = 1;
        private int r = 1;

        public double out_x { get; set; default = 0.0; }
        public double out_y { get; set; default = 0.0; }

        public override void run() {
            glfwGetWindowSize(out w, out h);
            if (w != 0 && h != 0) {
                r = w < h ? w : h;
                glfwGetMousePos(out x, out y);
                out_x = (double) (x - (w >> 1)) /  (w >> 1);
                out_y = (double) (y - (h >> 1)) / -(h >> 1);
            }
        }
    }
}