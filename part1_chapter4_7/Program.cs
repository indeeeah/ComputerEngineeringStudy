using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2 {
    public class Monster {
        public string name;
        public virtual void Attact() {
            Console.WriteLine("공격 수행");
        }
    }

    public class Ork : Monster {
        public override void Attact() {
            base.Attact();  // base는 부모클래스 , 공격수행 뒤 오크족장이 출력됨
            name = "오크 족장";
            Console.WriteLine(name + ": 오크 공격");
        }
    }

    class Program {
        static void Main(string[] args) {
            Monster monster = new Monster();
            monster.Attact();
            Ork ork = new Ork();
            ork.Attact();
            Console.ReadLine();
        }
    }
}