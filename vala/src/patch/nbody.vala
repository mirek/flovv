using Gee;
using GL;
using Flovv;

namespace Flovv.Patch {
    public class NBody : Consumer {
        public float in_r { get; set; default = 0.5f; }

        public int in_n { get; set; default = 256; }
        public float in_gravity { get; set; default = 0.001f; }

        private Points3d points = new Points3d();
        private List<float?> masses = new ArrayList<float?>();
        private Points3d velocities = new Points3d();
        
        public override void run() {
            update();
            draw();
        }
        
        private void draw() {
            glPushMatrix();
            {
                glEnable(GL_BLEND);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
                float[] color = { 0.0f, 0.0f, 1.0f, 1.0f };
                int i = 0;
                foreach (Point3d point in points) {
                    Point3d v = velocities[i];
                    // float d = velocities[i].distance();
                    float g = 5.0f;
                    
                    color[0] = 1.0f;
                    color[1] = 1.0f;
                    color[2] = 1.0f;
                    color[3] = 0.5f;

                    glPointSize(masses[i] * 5.0f);
                    glBegin(GL_POINTS); 
                    glColor4fv(color);
                    glVertex3f(point.x, point.y, point.z);
                    glEnd();

                    // glLineWidth(masses[i] * 7.5f);
                    
                    glBegin(GL_LINES);
                    color[0] = 0.0f;
                    color[1] = 1.0f;
                    color[2] = 0.0f;
                    color[3] = 1.0f;
                    glColor4fv(color);
                    glVertex3f(point.x, point.y, point.z);
                    color[0] = 0.0f;
                    color[1] = 1.0f;
                    color[2] = 0.0f;
                    color[3] = 0.0f;
                    glColor4fv(color);
                    glVertex3f(point.x - v.x * g, point.y - v.y * g, point.z - v.z * g);
                    glEnd();
                    
                    i++;
                }
                glDisable(GL_BLEND);
            }
            glPopMatrix();
        }

        private void update() {
            resize();
            
            // Calculate velocities
            for (int i = 0; i < in_n; i++) {
                Point3d pi = points[i];
                Point3d velocity = velocities[i];
                for (int j = 0; j < in_n; j++) {
                    if (i != j) {
                        Point3d pj = points[j];
                        float x = pj.x - pi.x;
                        float y = pj.y - pi.y;
                        float z = pj.z - pi.z;
                        float d2 = x*x + y*y + z*z + 0.0001f; // eps2
                        float d6 = d2 * d2 * d2;
                        float idc = (0.00000005f * 1.0f) / (float) Math.sqrt(d6);
                        float s = 10.0f * masses[j] * idc;
                        velocity.x += x * s;
                        velocity.y += y * s;
                        velocity.z += z * s;
                    }
                }
            }
            
            // Move
            for (int i = 0; i < in_n; i++) {
                Point3d p = points[i];
                Point3d v = velocities[i];
                p.x += v.x;
                p.y += v.y;
                p.z += v.z;
                
                // Bounce
                if (p.x < -1.0f || p.x > 1.0f) v.x *= -1.0f;
                if (p.y < -1.0f || p.y > 1.0f) v.y *= -1.0f;
                if (p.z < -1.0f || p.z > 1.0f) v.z *= -1.0f;
            }
        }

        private void resize() {
            if (in_n != points.size) {
                points.clear();
                masses.clear();
                velocities.clear();
                for (int i = 0; i < in_n; i++) {
                    Point3d p = Point3d.new_random_cube();
                    p.z = 0.0f;
                    points.add(p);
                    masses.add((float) Random.next_double());
                    velocities.add(Point3d.new_random_cube(0.01f));
                }
            }
        }
    }
}
