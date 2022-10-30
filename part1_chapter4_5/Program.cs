using System;
using System.Collections.Generic;

namespace ConsoleApp1 {
    class Program {
        static void Main(string[] args) {
            List<string> list = new List<string>();
            list.Add("김수민");
            list.Add("이순신");
            list.Add("홍길동");
            Console.WriteLine(list[0]);
            Console.WriteLine(list[1]);
            Console.WriteLine(list[2]);
            Console.ReadLine();
        }
    }
}