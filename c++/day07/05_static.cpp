//类的静态成员变量
# include <iostream>
using namespace std;

//普通成员变量：属于对象，对象的生命期
//静态成员变量: 不属于对象，进程级生命期

class A{
public:
    A(){

    }
int m_i;
static int m_si;
};
//静态成员变量，类内声明，类外定义
int A::m_si = 0;

int main(void){
    A a,b;
    //静态成员变量不属于对象，不保存在对象内部
    cout << "a对象的大小"  << sizeof(a) << endl; // 4
    cout << "b对象的大小" << sizeof(b) << endl; // 4

    //类的静态成员变量
    A::m_si = 888;
    cout << "a.m_si = " << A::m_si << endl;
    cout << "b.m_si = " << A::m_si << endl;

    a.m_si = 999;
    cout << "a.m_si = " << A::m_si << endl;
    cout << "b.m_si = " << A::m_si << endl;

    b.m_si = 110;
    cout << "a.m_si = " << A::m_si << endl;
    cout << "b.m_si = " << A::m_si << endl;

}