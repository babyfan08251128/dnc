//同一作用域函数重载
#include <iostream>
using namespace std;
//在同一作用域中，函数名相同，形参表不同参数个数，参数类型，参数顺序)构成重载
//根据实参类型和形参类型进行匹配，调用最匹配的函数
//不同作用域的同名函数是隐藏关系
namespace ns1{
    void foo(char* c,short s){
        cout << "1.foo(char* short)" << endl;
    }

    void foo(int i,double d){
        cout << "2.foo(int,double)" << endl;
    }

}

namespace ns2{
    void foo(const char* c,short s){
        cout << "3.foo(const char *,short)" << endl;
    }

    void foo(double d,int i){
        cout << "4.foo(double,int)" << endl;
    }
}

int main(void){
    using namespace ns1;//命名空间指令，ns1中的内容从这行开始在当前作用域中可见
    using ns2::foo;//命名空间声明，ns2中的foo从这行开始引入当前作用域
    
    char* c;
    short s;
    foo(c,s);
    return 0;
}