//重载匹配的优先级
#include <iostream>
using namespace std;

//重载解析顺序
//完全匹配>常量转换>升级转换>标准转换>自定义转换>省略号匹配

void foo(char* c,short s){
    cout << "1.foo(char* short)" << endl;
}

void foo(const char* c,short s){
    cout << "2.foo(const char *,short)" << endl;
}

void foo(char* c,int s ){
    cout << "3.foo(char*,int)" << endl;
}

void foo(char* c,char s ){
    cout << "4.foo(char*,char)" << endl;
}

void foo(...){
    cout << "4.foo(...)" << endl;
}

int main(){
    //普通函数调用重载函数，根据实参类型和形参类型匹配
    //重载函数的形参类型可以更加严格，不能变宽松，例如char*c 找不到可以匹配const char* c。相反则不行、
    char* c;
    short s;
    foo(c,s);  //优先找1，如果没有1则是2，

    //指针类型调用重载函数，根据函数本身的类型来确定调用哪一个foo
    //将函数指针pfunc初始化为指向foo的地址。函数foo必须匹配先前的声明的函数指针的签名，即接收const char*，short 作为参数，返回void
    //声明一个函数指针，接收两个参数为const char*,short，返回值类型为void
    //
    void(*pfunc)(const char*,short ) = foo;
    pfunc(c,s);

}
