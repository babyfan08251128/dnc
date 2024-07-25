//拷贝构造函数被调用的时间点
#include <iostream>
#include <cstring>
using namespace std;
class Human{
public:
    Human(int age = 0,const char* name = "匿名"){
        cout << "Human类的缺省构造函数被调用" << endl;
        m_age = age;
        m_name = name;
    }
    Human(const Human& that){
        cout << "Human类的拷贝构造函数被调用" << endl;
        m_age = that.m_age;
        m_name = that.m_name;
    }

    void getInfo(){
        cout << "姓名:" << this->m_name << ",年龄:" << this->m_age << endl;
    }

private:
    int m_age;
    string m_name;
};

//foo函数的参数v将被初始化类生成对象的一个副本
void foo(Human v){

}

Human bar(){
    Human m;
    return m;
}

int main(void){
    Human h2(22,"张飞");
    cout << "------" << endl;
    Human h3(h2);
    h3.getInfo();
    cout << "------" << endl;

    foo(h3);
    cout << "------" << endl;

    Human h4 = bar();
    return 0;
}