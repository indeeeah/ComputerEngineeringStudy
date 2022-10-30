using System;
using System.Collections.Generic;

namespace ConsoleApp1 {
    class Program {
        static void Main(string[] args) {
            Dictionary<string, int> dictionary = new Dictionary<string, int>(); // key와 value값
            dictionary["김수민"] = 100;
            dictionary["홍길동"] = 83;
            dictionary["이순신"] = 78;
            if (dictionary.ContainsKey("김수민")) {
                Console.WriteLine("김수민 성적 : " + dictionary["김수민"] + "점");
            }
            
            foreach(KeyValuePair<string, int> pair in dictionary) {
                Console.WriteLine("[" + pair.Key + "]: " + pair.Value + "점");
            }
            Console.ReadLine();
        }
    }
}