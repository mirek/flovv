using Flovv;
using GL;

namespace Flovv.Patch {
    public class Cloud : Consumer {
        public float in_rotate_x { get; set; default = 0.0f; }
        public float in_rotate_y { get; set; default = 0.0f; }
        public float in_rotate_z { get; set; default = 0.0f; }

        public float in_r { get; set; default = 0.25f; }

        public float in_x { get; set; default = 0.0f; }
        public float in_y { get; set; default = 0.0f; }
        public float in_z { get; set; default = 0.0f; }

        public int in_n { get; set; default = 1024; } // Number of points

        private Points3d points = new Points3d();

        public override void run() {
            update();
            glPushMatrix();
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
            {
                glTranslatef(in_x, in_y, in_z);
        
                glRotatef(in_rotate_x, 1.0f, 0.0f, 0.0f);
                glRotatef(in_rotate_y, 0.0f, 1.0f, 0.0f);
                glRotatef(in_rotate_z, 0.0f, 0.0f, 1.0f);
        
                glScalef(in_r, in_r, in_r);
        
                float f = 0.75f;

                // glBegin(GL_POINTS);
                // {
                    // glLineWidth(3);
                    float[] color = { 0.0f, 0.0f, 1.0f, 1.0f };
                    foreach (Point3d point in points) {
                        color[0] = 1.0f; // ((in_r * 0.5f) + point.x) / in_r;
                        color[1] = 1.0f; // ((in_r * 0.5f) + point.y) / in_r;
                        color[2] = 1.0f; // ((in_r * 0.5f) + point.z) / in_r;
                        color[3] = 0.5f;
                
                        glBegin(GL_LINES); 
                        glColor4fv(color);
                        glVertex3f(point.x * f, point.y * f, point.z * f);
                        glColor4f(0, 0, 0, 0);
                        glVertex3f(point.x, point.y, point.z);
                        // glVertex2i( ax, ay); 
                        // glVertex2i( bx, by); 
                        glEnd();
                        // glVertex3f(point.x, point.y, point.z);
                    }
                // }
                // glEnd();
            }
            glDisable(GL_BLEND);
            glPopMatrix();
        }

        private void update() {
            resize();
        }

        private void resize() {
            if (in_n != points.size) {
                points.clear();
                for (int i = 0; i < in_n; i++) {
                    points.add(new Point3d(0.0f, 0.0f, 0.0f));
                }
        
                foreach (Point3d point in points) {
                    float u = (float) Random.next_double();
                    float v = (float) Random.next_double();
                    float a = (float) (2.0 * Math.PI * u);
                    float b = (float) (Math.acos(2.0f * v - 1));
                    point.set_polar(1.0f, a, b);
                }
            }
        }
    }
}
