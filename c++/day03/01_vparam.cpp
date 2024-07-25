//引用的应用
//引用型形参

# include <iostream>
using namespace std;

void Swap(int& x,int& y){//非常引用型形参，可以在函数内部修改实参
    int z = x;
    x = y;
    y = z;
}

void Swap(int* x,int* y ){
    int z = *x;
    *x = *y;
    *y = z;
}

//非常引用型形参，可以使用变量，不可以修改变量
void Print(const int& x,const int& y){
    //x = 666  表达式必须是可修改的左值
    cout << "x = " << x << ", y = " << y << endl;

}

int main(void){
    int a = 10;
    int b = 20;
    // Swap(a, b);
    // cout << "a = " << a << ", b = " << b << endl;
    Swap(&a,&b);
    cout << "a = " << a << ", b = " << b << endl;

    Print(666 ,888);

}