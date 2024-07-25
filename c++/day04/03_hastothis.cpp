//必须自己写this的情况
# include <iostream>
# include <cstring>

using namespace std;

class Integer{
public:
    void SetInfo(/*Integer* this*/int num){
        this->num = num;
    }
    void GetInfo(/*Integer* this*/){
        cout << "num = " << this->num << endl;
    }

    Integer& increment(/*Integer* this*/){
        return *this;//返回当前对象的引用
    } 
private:
    int num;
};

int main(void){
    Integer e;
    e.SetInfo(20);
    e.GetInfo();
    e.increment().increment().increment();
}