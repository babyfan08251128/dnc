//类的静态成员变量和静态成员函数
#include <iostream>
using namespace std;

//普通成员函数，必须利用对象来调用
//静态成员函数，不是必须利用对象来调用
class A{
public:
    int m_i;
    void foo() const{
        cout << "foo is invoked" << endl;
        cout << m_i << endl;
        cout << m_si << endl;
        bar();
    }
    static int m_si;
    static void bar(/*无this指针*/){
        cout << "bar is invoked " << endl;
        cout << m_si << endl;
        //cout << m_i << endl;//eror
        //foo();


    }
};
int A::m_si = 0;

int main(){
    A a,b;
    a.foo();
    b.foo();

    A::bar();
    a.bar();
    b.bar();
}