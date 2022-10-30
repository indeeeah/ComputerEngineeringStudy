using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2 {
    public abstract class Monster {
        public abstract void Attack();
    }
    // 추상클래스이기 때문에 무조건 Attack을 구현 해주어야 한다.
    public class Ork : Monster {
        public override void Attack() {
            Console.WriteLine("오크 공격");
        }
    }

    class Program {
        static void Main(string[] args) {
            // 추상클래스를 그 인스턴스를 바로 사용 할 수 없다.
            // Monster monster = new Monster();
            // monster.Attack();
            Ork ork = new Ork();
            ork.Attack();
            Console.ReadLine();
        }
    }
}