// 函数的缺省值,带默认值的形参
#include <iostream>
using namespace std;


void foo(int a = 1,float b = 0.1,double c = 5.67,short d = 6,char e = 'q');
void foo(int a,float b,double c,short d,char e){
    cout << e << endl;

}
void foo(int i){

}

int main(){
    foo(12,3.45,6.78,34); //q
    foo(12,3.45,6.78,34,'w'); //w
    //foo(12);//多个重载
    return 0;

}