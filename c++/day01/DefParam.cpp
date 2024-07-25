#include <iostream>
#include <cstring>
using namespace std;


//C++的结构体中可以直接定义成员函数，在成员函数内部可以直接访问结构体内的成员变量，无需通过结构体对象调用
void TestSurct(){
    struct Student{  // 定义结构体
        int m_age;
        char m_name[256];

        Student(){
            cout << "析构函数" << endl;
        }

        void getInfo(){
            cout << "get_info:姓名:" << m_name << "    get_info:年龄:" << m_age << endl;
        }
    };
    Student s;//定义一个Student结构体对象s
    s.m_age = 22;
    strcpy(s.m_name,"张三");
    cout << "姓名:" << s.m_name <<"    年龄:" << s.m_age << endl;
    s.getInfo();

}

//c++共用体
void TestUnion(void){
    union {//匿名联合，共用一块内存，同一时间只能使用其中一个变量
        int i;
        char c[4];
    };
    i = 0X12345678;
    // x  V  4  因为c[4]是char类型的，所以会以char类型输出，想要是整数类型，需要类型转换 
    //78  56  34  12  
    cout << hex << (int)c[0] << "  "<< (int)c[1] << "  " << (int)c[2] << "  "  << (int)c[3]  << "  " << endl;

}

//c++枚举
void TestEnum(void){
    enum Color{
        red,
        green,
        blue
    };
    Color c = red;//只能通过枚举体内的变量赋值
    cout << c << endl;

}

//c++bool
void TestBool(){
    bool a = true;//1;
    bool b = false;//0;
    cout << "a = " << a << "    " << "b = " << b << endl;

}
int main(void){
    //TestSurct();
    //TestUnion();
    //TestEnum();
    TestBool();


}