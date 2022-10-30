using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Example1 {
    class Example {
        public static string data = "홍길동";
    }
}

namespace Example2 {
    class Example {
        public static string data = "김수민";
    }
}

namespace Program1 {
    class Program {

        enum Color { BLACK, BLUE, RED, GREEN };
        static void Main(string[] args) {
            Console.WriteLine(Example1.Example.data);
            Console.WriteLine(Example2.Example.data);
            
            Color color = Color.BLUE;
            if (color == Color.BLUE) {
                Console.Write("파란색입니다.");
            } else {
                Console.Write("파란색이 아닙니다.");
            }
            Console.ReadLine();
        }
    }
}