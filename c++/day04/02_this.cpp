//成员函数的形参
#include <iostream>
#include <cstring>
using namespace std;

class Human{
public:
    void SetInfo(/* Human* this */int age,const char* name){
        this->m_age = age;
        strcpy(this->m_name,name);
    }
    void GetInfo(/* human* this */){
        cout << "姓名:" << this->m_name << ",年龄:" << this->m_age << endl;

    }
private:
    int m_age;
    char m_name[256];
};

int main(void){
    Human h;
    cout << "h的大小" << sizeof(h) << endl;
    h.SetInfo(22,"呆呆");
    h.GetInfo();

    Human h1;
    cout << "h1的大小"  << sizeof(h1) << endl;
    h1.SetInfo(23,"棒棒");
    h1.GetInfo();
    return 0;

}