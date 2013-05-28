namespace Flovv.Patch {
    public class Multiply : Processor {
        public double in_a { get; set; default = 0.0; }
        public double in_b { get; set; default = 0.0; }
        public double out_value { get; set; default = 0.0f; }
        
        public override void run() {
            out_value = in_a * in_b;
        }
    }
}
