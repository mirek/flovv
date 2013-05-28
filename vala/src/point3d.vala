namespace Flovv {
    public class Point3d {
        public float x = 0.0f;
        public float y = 0.0f;
        public float z = 0.0f;

        public Point3d(float x = 0.0f, float y = 0.0f, float z = 0.0f) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
        
        public static Point3d new_random_cube(float r = 1.0f) {
            float x = (float) (Random.next_double() - 0.5) * r;
            float y = (float) (Random.next_double() - 0.5) * r;
            float z = (float) (Random.next_double() - 0.5) * r;
            return new Point3d(x, y, z);
        }

        public void set_polar(float r, float a, float b) {
            x = (float) (r * Math.cos(a) * Math.sin(b));
            y = (float) (r * Math.sin(a) * Math.sin(b));
            z = (float) (r * Math.cos(b));
        }
        
        public void add(Point3d point) {
            x += point.x;
            y += point.y;
            z += point.z;
        }
        
        public void substract(Point3d point) {
            x -= point.x;
            y -= point.y;
            z -= point.z;
        }
        
        public void zero() {
            set_xyz(0.0f, 0.0f, 0.0f);
        }
        
        public void set_xyz(float x, float y, float z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
        
        public float distance(Point3d? point = null) {
            float dx = x;
            float dy = y;
            float dz = z;
            if (point != null) {
                dx = x - point.x;
                dy = y - point.y;
                dz = z - point.z;
            }
            return (float) Math.sqrt(dx*dx + dy*dy + dz*dz);
        }
    }
}