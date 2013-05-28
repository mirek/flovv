namespace Flovv.Patch {
    
    [Description(nick = "sine", blurb = "Computes sine")]
    public class Sine : Processor {
        
        [Description(nick = "Input value", blurb = "Input value in radians")]
        public double in_x { get; set; default = 0.0; }
        
        [Description(nick = "Sine", blurb = "Sine value in [-1..1] range")]
        public double out_sine { get; set; default = 0.0f; }
        
        public override void run() {
            out_sine = Math.sin(in_x);
        }
    }
}
