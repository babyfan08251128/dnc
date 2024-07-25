//结构体(类)和变量(对象)
# include <iostream>
# include <cstring>

using namespace std;

//类:抽取事物特征的规则
class Human{
public:
    void setInfo(int age = 0,const char* name = "匿名"){
        cout << strcmp(name,"憨憨") << endl;//strcmp:判断两个字符串是否相同，相同返回0，不同返回1
        if(!strcmp(name,"憨憨")){
            cout << "范呆呆是憨憨" << endl;
            return;
        }
        m_age = age;
        strcpy(m_name,name);
    }
    void getInfo(){
        cout << "姓名:" << m_name << "年龄:" << m_age << endl;
    }
private:
    int m_age;
    char m_name[256];
};

int main(void){
    Human h; //定义h(给h分配内存空间)
            //在h所占据的内存空间中定义m_age;
            //在h所占据的内存空间中定义m_name;
    cout << "h的大小:" << sizeof(h) << endl;
    h.setInfo(22,"范呆呆");
    h.getInfo();
    return 0;

}