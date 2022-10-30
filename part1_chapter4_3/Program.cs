using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Main {
    public class Student {
        private int id;
        private string name;
        private int score;
        public Student(int id, string name, int score) {
            this.id = id;
            this.name = name;
            this.score = score;
        }
        public void Show() {
            Console.WriteLine("학번 : " + id);
            Console.WriteLine("이름 : " + name);
            Console.WriteLine("점수 : " + score);
        }
    }
    class Program {
        static void Main(string[] args) {
            Student student = new Student(215050049, "김수민", 98); // 동적 할당 : 가비지 콜렉터가 수거해주기 때문에 메모리 해제 할 필요 없음
            student.Show();
            Console.ReadLine();
        }
    }
}