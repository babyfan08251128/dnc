//初始化表----只能在构造函数中使用(指导编译器如何给定义出来的成员变量做初始化)

#include <iostream>
using namespace std;

class Human{
public:
    /*
    默认得构造函数
    Human()
    {
        int m_age;//初始值随机
        string m_name; //定义m_name,利用m_name.string();
    }
    */

    Human(int age = 0,const char * name = "匿名"):m_age(age),m_name(name)
    {
        //等同于：
        // int m_age = age;
        // string m_name(name);
        cout << "Human类的构造函数被调用" << endl;
    }

    //拷贝构造函数
    /* 默认得拷贝构造函数
    Human(const Human& that){
        int m_age = that.m_age;
        string m_name(that.m_name);
    }
    */

   Human(const Human& that):m_age(that.m_age),m_name(that.m_name){
        cout << "Human类的拷贝构造函数被调用" << endl;
   }
    
    Human& operator=(const Human& that){
        cout << "Human类的拷贝赋值函数被调用" << endl;
        this->m_age = that.m_age;
        this->m_name = that.m_name;

        return *this;

    }

    void getinfo()
    {
        cout << "姓名:" << m_name << " 年龄: " << m_age << endl;
    }
    //赋值构造函数
    ~Human()
    {
        cout << "Human类析构函数被调用" << endl;
    }

private:
    int m_age;
    string m_name;

};


int main(int agrc,const char* argv[])
{
    Human h;
    h.getinfo(); //匿名， 0；
    cout << "===============" << endl;
    Human h2(22,"范呆呆");
    h2.getinfo();
    cout << "===============" << endl;
    Human h3(h2);
    h3.getinfo();
    cout << "===============" << endl;
    Human h4;
    h4.getinfo();
    h4 = h3;
    h4.getinfo();
}