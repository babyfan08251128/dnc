//动态堆内存分配
# include <iostream>
# include <cstdlib>

using namespace std;

int main(void){
    //声明一个int类型的指针
    //利用malloc在堆上分配4个字节的内存，并返回分配内存的起始地址的指针
    //malloc返回的是void类型的指针，需要强制转换类型
    int* pm = (int*)malloc(4);
    cout << "*pm = " << *pm << endl;
    free(pm);
    pm = NULL;//释放后至为空

    int* pn = new int(100);
    cout << "*pn = " << *pn << endl;
    delete pn;//释放内存
    pn = NULL;

    //new一个有4个元素的数组
    int* pi = new int[4]{10,20,30,40};
    for(int i = 0;i < 4;i++){
        cout << pi[i] << "  " ;
    }
    cout << endl;
    delete[] pi;

    //不管是几维数组，都应该当做一维数组来看待
    int(*p)[4] = new int[3][4];
    delete[] p;

    try{
        new int(0xFFFFFFFF);
    }
    catch(...){

    }
    return 0;
}