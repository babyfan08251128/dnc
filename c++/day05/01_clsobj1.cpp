//构造函数:1，函数名必须与类名相同；2，没有返回值类型
//构造函数被调用的时间:定义对象的同时，自动被调用
//构造函数的作用:定义对象的每一个成员变量
# include <iostream>
#include <cstring>
using namespace std;

class Human{
public:
    Human(int age = 0,const char* name = "匿名"){//构造函数
        cout << "Human类的有参构造函数调用" << endl;
        this->m_age = age;
        strcpy(this->m_name,name);
    }

    void GetInfo(){
        cout << "姓名:" << m_name << ",年龄" << m_age << endl;
    }

private:
    int m_age;
    char m_name[256];
};


int main(){
    Human h(22,"张三");
    cout << "Human类定义的对象h定义完成" << endl;
    h.GetInfo();
}