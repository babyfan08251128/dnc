//引用和指针在C++层面的差别
# include <iostream>
using namespace std;

int main(void){
    int a = 10;
    int b = 20;

    //指针可以做初始化也可以不做初始化
    //指针在初始化后可以变更他所指向的内存空间
    int *p;
    int* pa = &a;
    pa = &b;

    //引用必须初始化，
    //初始化后不可以变更他所指向
    //int& pb1;
    int& ra = a;
    ra = b;//这里是赋值操作，不是重定向引用

    //存在空指针不存在空引用
    pa = NULL;
    //ra = NULL; //converting to non-pointer type ‘int’ from NULL [-Wconversion-null]

    //存在二级指针，不存在二级引用
    int** ppa = &pa;
    //int&& rra = ra;

    //存在指针的引用，不存在引用的指针
    int*& rpa = pa;//存在指针的引用
    //int&* pra = &ra;

    //存在指针数组，不存在引用数组
    int x,y,z;
    int* p[3] = {&x,&y,&z};
    //int& r[3] = {x,y,z};

    int arr[3];
    int (&parr)[3] = arr;

}