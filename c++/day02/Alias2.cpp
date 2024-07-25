//左值与右值

# include <iostream>
using namespace std;

int foo(){
    int m  = 888;
    return m;
}

int main(void){
    int a = 10;
    int& ra = a;//引用
    const int& cra  = a;
    
    const int b = 10;
    //int& rb = b;//类型错误
    const int& crb  = b;

    const int& rf = foo();
    return 0;
}