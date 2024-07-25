//必须初始化
# include <iostream>
#include <cstring>

using namespace std;

class Human
{
public:
    //m_score是常亮成员变量，必须在初始化列表中初始化
    //m_len,是基于name计算得到的，所以也必须在初始化列表中初始化
    Human(int age = 0,const char* name = "匿名",const float score = 0.0):
    m_age(age),m_name(name),m_len(strlen(name)),m_score(score)
    {

    }

    void getinfo()
    {
        cout << "姓名: " << m_name << ", 名字字符长度: " << m_len << ", 年龄: " << m_age << ", 分数: " << m_score << endl;
    }
private:
    int m_len;
    int m_age;
    string m_name;
    const float m_score;
};

int main(int argc,const char* argv[])
{
    Human h1(22,"范呆呆",9.9);
    h1.getinfo();
}