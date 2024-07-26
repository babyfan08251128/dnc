//析构函数

#include <iostream>
using namespace std;

class Human
{
public:
    Human(int age = 0,const char* name = "匿名"):m_age(age),m_name(name)
    {
        cout << "Human类的缺省构造函数被调用" << endl;
    }

    ~Human()
    {
        cout << "Human类的析构函数被调用" << endl;
    }

    void getinfo()
    {
        cout << "姓名:" << m_name << ", 年龄:" << m_age << endl;
    }
private:
    int m_age;
    string m_name;
};

int main()
{
    Human h1(22,"范呆呆");
    h1.getinfo();

}//h1.~Human()   释放h1本身所占的内存空间