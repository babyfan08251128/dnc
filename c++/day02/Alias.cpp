//引用:一块内存的别名
#include <iostream>
using namespace std;

int main(void){
    int a = 10;
    int& b = a;//b是a的引用，b也指向a的那块内存空间

    b = 20;

    cout << "a = " << a << ", b = " << b << endl;
    cout << "a = " << a << ", b = " << b << endl;

    int c =30;
    b = c;//这里不是修改b的引用，使引用指向c的内存空间，而是赋值c内存的值给b(a对应的内存)
    cout << "a = " << a  << ", b = " << b << ", c = " << c << endl;
    cout << "a = " << a  << ", b = " << b << ", c = " << c << endl;

    int& d = b;//不是引用的引用，而是d跟b是一样的引用，都指向a的内存空间
    cout << "&a : " << &a << ", &b : " << &b << ", &d : " << &d << endl;

    const int e = 10;
    //int& f = e;//别名的类型不能比实际变量名字的类型更加宽松
    const int& g = e;

    const int& h = a;//别名的类型可以比实际变量的类型更加严格

    return 0;

}