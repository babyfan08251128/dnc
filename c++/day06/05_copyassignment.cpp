//拷贝赋值函数，函数重载
#include <iostream>
#include <string>
using namespace std;

class Human{
public:
    //默认构造函数
    Human(int age = 0,const char* name= "匿名"):m_age(age),m_name(name){
        cout << "默认构造函数被调用" << endl;
    }

    //默认拷贝构造函数
    Human(const Human& that){
        m_age = that.m_age;
        m_name = that.m_name;
    }

    Human& operator=(const Human& that){
        cout << "Human类的拷贝赋值函数被调用" << endl;
        this->m_age = that.m_age;
        this->m_name = that.m_name;
        return *this;

    } 


    void getInfo(){
        cout << "姓名:" << this->m_name << ",年龄:" << this->m_age << endl;  
    }
private:
    int m_age;
    string m_name;
};

int main( void ){
    cout << "------------------h的创建信息--------------------" << endl;
    Human h; // 定义h,利用h.Human()  h维护的内容(匿名，0)
    h.getInfo();

    cout << "------------------h2的创建信息--------------------" << endl;
    Human h2(22,"张飞"); // 定义h2,利用h2.Human(22,"张飞") h2维护的内容(22,"张飞")
    h2.getInfo();
    
    cout << "------------------h3的创建信息--------------------" << endl;
    Human h3(h2); // =h2; 定义h3,利用h3.Human(h2)
    h3.getInfo();
    
    cout << "------------------h4的创建信息--------------------" << endl;
    Human h4; // 定义h4，利用h4.Human() --> h4维护的内容(匿名,0)
    cout << "h4被赋值前---:";
    h4.getInfo();
    h4 = h3; // h4.operator=
    cout << "h4被赋值后---:";
    h4.getInfo();
    
    return 0;
}