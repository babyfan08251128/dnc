#include <iostream>
#include <string>
using namespace std;

class A{
public:
    A(int i = 0){
        m_i = i;
    }
private:
    int m_i;
};

class Human{
public:
    Human(int age = 0,const char* name = "匿名"){
        /*
        默认构造函数
        int m_age;
        string m_name;
        A m_a
        */
        cout << "Human类的缺省构造函数被调用" << endl;
        m_age= age;
        m_name = name;
    }
    void getInfo(){
        cout << "姓名:" << this->m_name << "," << "年龄" << this->m_age << endl;
    }
private:
    int m_age;      //基本类型的成员变量
    string m_name;  //类类型的成员变量
    A m_a;  //类类型的成员变量
};

int main(void){
    Human h1;
    h1.getInfo();

    Human h2(22,"范呆呆");
    h2.getInfo();

}