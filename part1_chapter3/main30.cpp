#include <iostream>
#include <string>

using namespace std;

template <typename T = int>
class Data {
    private:
        T data;
    public:
        Data(T data) : data(data) { }
        void setData(T data) {
            this->data = data;
        }
        T getData() {
            return data;
        }
};

int main(void) {
    // 타입에 대한 지정이 없었을 때 <typename T = int> 로 사용하겠다.
    Data<> data1(1);
    Data<string> data2("김수민");
    cout << data1.getData() << ":" << data2.getData() << "\n";

    return 0;
}