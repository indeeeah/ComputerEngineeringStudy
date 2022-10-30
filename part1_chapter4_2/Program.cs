using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2 {
    struct Adder {
        public int x, y;
        public Adder(int x, int y) {
            this.x = x;
            this.y = y;
        }
        public string GetResult() {
            return x + " + " + y + " = " + (x + y);
        }
    }
    class Program {
        static void Main(string[] args) {
            // int a = 5;
            // // 프로그래머의 편의성을위해 자료구조를 바꿀 수 있다.
            // string b = a.ToString();
            Adder adder = new Adder(3, 7);
            Console.WriteLine(adder.GetResult());
            Console.ReadLine();
        }
    }
}