//必须自己写析构函数的情况
#include <iostream>

using namespace std;

class A{
public:
    A(int i):m_i(i),m_p(new int ),m_f(i){

    }
    ~A(){
        delete m_p;//自己在类内创建的指针类型的成员变量，需要手动释放内存；
        cout << "析构函数被调用" << endl;
    }
private:
    int m_i;
    int* m_p;
    int m_f;
};

int main(){
    A a(1);
    return 0;

}