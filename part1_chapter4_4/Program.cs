using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Main {
    class Stack<T> {
        T[] stack;
        int top = -1;
        public Stack() {
            stack = new T[100];
        }
        public void Push(T element) {
            stack[++top] = element;
        }
        public T Pop() {
            return stack[top--];
        }
    }

    class Program {
        static void Main(string[] args) {
            Stack<int> stack = new Stack<int>();
            stack.Push(3);
            stack.Push(5);
            stack.Push(7);
            Console.WriteLine(stack.Pop());
            Console.WriteLine(stack.Pop());
            Console.WriteLine(stack.Pop());
            Console.ReadLine();
        }
    }
}