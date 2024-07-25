//缺省构造函数
#include <iostream>
#include <cstring>
using namespace std;

class Human{
public:
//如果一个类没有提供任何构造函数，编译器将提供一个无参的构造函数
/*
    Human(){
        int m_age;//定于m_age;随机值
        string m_name//利用m_name.string()
    }
*/
    Human(int age = 0,const char* name = "匿名"){
        cout << "Human类的缺省构造函数被调用" << endl;
        m_age = age;
        m_name = name;
    }

    void getInfo(){
        cout << "姓名:" << this->m_name << "," << "年龄" << this->m_age << endl;
    }
private:
    int m_age;
    string m_name;
};

int main(void){
    Human h;
    h.getInfo();

    Human h2(22,"范呆呆");
    h2.getInfo();

}