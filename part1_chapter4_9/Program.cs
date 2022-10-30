using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2 {
    public interface Monster {
        void Attack();
        void Defence();
    }
    public class Ork : Monster {
        public void Attack() {
            Console.WriteLine("오크 공격");
        }
        public void Defence() {
            Console.WriteLine("오크 방어");
        }
    }

    class Program {
        static void Main(string[] args) {
            Ork ork = new Ork();
            ork.Attack();
            ork.Defence();
            Console.ReadLine();
        }
    }
}