#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Time {
    friend class Date;  // frined 키워드 때문에 Date클래스에서 Time 클래스를 사용할 수 있음
    private:
        int hour, min, sec;
    public:
        void setCurrentTime() {
            time_t currentTime = time(NULL);
            // localtime 함수를 이용하여 매개변수를 넣어 현재 시간을 알 수 있다.
            struct tm *p = localtime(&currentTime);
            hour = p->tm_hour;
            min = p->tm_min;
            sec = p->tm_sec;
        }
};

class Date {
    private:
        int year, month, day;
    public:
        Date(int year, int month, int day) : year(year), month(month), day(day) { }
        void show(const Time &t) {
            cout << "지정된 날짜 : " << year << "년 " << month << "월 " << day << "일" << '\n';
            // friend class로 되어있기 때문에 t.getHour()로 할 필요 없이 t.hour로 바로 접근할 수 있다. 
            cout << "현재 시간 : " << t.hour << " : " << t.min << " : " << t.sec << '\n';
        }
};

int main(void) {
    Time time;
    time.setCurrentTime();
    Date date = Date(2022, 12, 22);
    date.show(time);

    return 0;
}