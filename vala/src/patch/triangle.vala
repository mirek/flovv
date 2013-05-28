using GL;

namespace Flovv.Patch {

    public class Triangle : Consumer {
        public float in_x = 0.0f;
        public float in_y = 0.0f;
        public float in_z = 0.0f;

        public float in_scale = 1.0f;

        public override void run() {
            glBegin (GL_TRIANGLES);
            {
                glVertex3f (in_x           , in_y           , in_z);
                glVertex3f (in_x + in_scale, in_y + in_scale, in_z);
                glVertex3f (in_x - in_scale, in_y + in_scale, in_z);
            }
            glEnd ();
        }
    }
}