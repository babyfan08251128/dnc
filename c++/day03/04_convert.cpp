//显式(强制)类型转换
# include <iostream>
using namespace std;

int main(){
    int a;double b;float c;short d;char e;

    //从右到左赋值，发生隐式类型转换
    a= b = c = d = e;
    e = d = c = b = e;

    //任何其他类型的指针到void * 都可以隐式转换
    void* pv = &a;
    pv = &b;
    pv = &c;
    pv = &d;
    pv = &e;

    //void* 到任何类型的指针都必须强转(显式转换)
    //如果一个强制类型的反向是一个隐式转换类型，那么可以用类型转换关键字
    int* pa = static_cast<int* >(pv);     
    double* pb = static_cast<double*>(pv);
    float* pf = static_cast<float*>(pv);
    short* ps = static_cast<short*>(pv);
    char* pc = static_cast<char*>(pv);

    //任何类型的非常指针到同类型的常指针都可以隐式转换
    const int* cpa = pa;
    const double* cpb = pb;
    const float* cpf = pf;
    const short* cps = ps;
    const char* cpc = pc;
    //任何类型的常指针到同类型的非常指针都必须强转
    pa = const_cast<int*>(cpa);
    pb = const_cast<double*>(cpb);
    pf = const_cast<float*>(cpf);
    ps = const_cast<short*>(cps);
    pc = const_cast<char*>(cpc);

    //除了void*之外，其他类型的指针之间必须强转
    pa = reinterpret_cast<int*>(pb);
    pa = reinterpret_cast<int*>(38);
    return 0;

}