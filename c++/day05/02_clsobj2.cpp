//c++提供的11种定义对象的方法
# include <iostream>
#include <cstring>
using namespace std;

class Human{
public:
    Human(int age = 0,const char* name = "匿名"){
        cout << "Human类的有参构造函数被调用"  << endl;
        this->m_age = age;
        strcpy(this->m_name,name);
    }
    void GetInfo(){
        cout << "姓名: " << this->m_name << ",年龄: " << this->m_age << endl; 

    };
private:
    int m_age;
    char m_name[256];
};


int main(){
    Human(32,"马超").GetInfo();

    Human h(22,"张飞");
    h.GetInfo();

     //Human h2();//类似于int h2();是一个函数声明，不是定义一个对象
     //h2.GetInfo();

     Human h2;
     h2.GetInfo();

    Human h3[3];
    for(int i = 0;i < 3 ;i++){
        h3[i].GetInfo();
    }

    Human h4[3]{Human(11,"张飞"),Human(12,"赵云"),Human(13,"关羽")};
    for (int i = 0 ;i < 3;i ++){
        h4[i].GetInfo();
    }

    Human h5[]{Human(11,"张飞"),Human(12,"赵云"),Human(13,"关羽"),Human(14,"刘备")};
    for (int i = 0 ;i < sizeof(h5)/sizeof(h5[0]);i ++){
        h5[i].GetInfo();
    }

    //在堆上创建对象
    Human* ph = new Human;
    (*ph).GetInfo();//ph->GetInfo();
    delete ph;
    ph = NULL;

    Human* ph2 = new Human();//new的时候可以在构造函数后面加()
    ph2->GetInfo();
    delete ph2;
    ph2 = NULL;

    Human* ph3 = new Human(22,"张飞飞");
    ph3->GetInfo();
    delete ph3;
    ph3 = NULL;

    Human* ph4 = new Human[3];
    for(int i = 0 ; i < 3 ; i++){
        ph4[i].GetInfo();
    }
    delete[] ph4;
    ph4 = NULL;

    Human* ph5 = new Human[3]{Human(11,"张飞飞"),Human(12,"赵云云"),Human(13,"关羽羽")};
    for(int i = 0 ; i < 3 ; i++){
        ph5[i].GetInfo();
    }
    delete[] ph5;
    ph5 = NULL;





}