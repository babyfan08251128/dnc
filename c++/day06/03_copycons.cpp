//拷贝构造函数
# include <iostream>
#include <string>
using namespace std;

class Human{
public:
    /*
    类如果没有构造函数，则会提供一个默认的构造函数，如下：
    Human(){
        int m_age;
        string m_name;
    }
    */
    Human(int age = 0,const char* name = "匿名"){
        cout << "Human类的缺省构造函数被调用" << endl;
        m_age = age;
        m_name = name;

    }
    //如果类没有提供拷贝构造函数，编译器将提供一个默认的拷贝构造函数
    Human(const Human& that){
        cout << "Human类的拷贝构造函数被调用" << endl;
        m_age = that.m_age;
        m_name = that.m_name;
    }

    void getInfo(){
        cout << "姓名:" << this->m_name << ",年龄:" << this->m_age << endl;
    }

private:
    int m_age;//基础类型成员变量
    string m_name;//类类型成员变量
};


int main(void){
    cout <<"================h的创建===============" << endl;
    Human h;
    h.getInfo();
    cout <<"================h1的创建===============" << endl;
    Human h1(22,"范呆呆");
    h1.getInfo();
    cout <<"================h1的创建===============" << endl;
    Human h2 = h1;   //等于h2(h1);  //利用h3.Human(h2)
    h2.getInfo();
    return 0;

}