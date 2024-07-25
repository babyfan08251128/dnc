//类型转换构造函数  ---指定  源类型 到目标类型  的转换规则
#include <iostream>
using namespace std;

class Cat
{
public:
    explicit Cat (const char* name):m_name(name){
        cout << "Cat 类的类型转换构造函数被调用" << endl;
    }
private:
    string m_name;
    friend class Dog;//友元类

};

class Dog
{
public:
    Dog(const char* name):m_name(name)
    {
        
    }

    explicit Dog(const Cat& c):m_name(c.name){

    }

    void talk()
    {
        cout << m_name << ": 汪汪~~~" << endl;
    }
private:
    string m_name;
};