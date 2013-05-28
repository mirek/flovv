
namespace Flovv.Patch {
    public class Frame : Provider {
        public uint64 out_frame { get; set; default = 0; }
        public override void run() {
            out_frame++;
        }
    }
}
