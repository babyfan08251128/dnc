// 类中有指针成员，默认拷贝构造进行浅拷贝操作，存在缺陷
# include <iostream>

#include <cstring>

using namespace std;

class String{
public:
    //构造函数
    String(const char* psz = "") : m_psz(new char[strlen(psz) + 1]){
        strcpy(m_psz,psz);
    }

    ~String(/*String* this*/){
        cout << "析构函数释放m_psz" << endl;
        delete [] this->m_psz;
    }

    char* c_str(){
        return m_psz;
    }

    //默认拷贝构造函数，只进行地址的拷贝，没有复制地址指向的数据
    // String (const String& that):m_psz(that.m_psz){
    // }

    //深拷贝
    String(const String& that):m_psz(new char[strlen(that.m_psz) + 1]){
        //m_psz = new char [strlen(that.m_psz) + 1];
        strcpy(m_psz,that.m_psz);//新创建一个内存地址，复制源地址空间中的值
    }

    //默认的赋值构造函数 
    /*String operator=(const String& that){
        this->m_psz = that.m_psz;
        return *this;
    }*/

    //深拷贝赋值构造函数
    String operator=(const String& that){
        if(this != &that){//防止自复制
            delete[] this->m_psz;//释放旧资源
            this->m_psz = new char[strlen(that.m_psz) + 1];
            strcpy(this->m_psz,that.m_psz);
        }
        return *this;
    }
private:
    char* m_psz;
};

int main(){
    String s1("hello");
    cout << "S1:" << s1.c_str() << ", s1中m_psz指向的堆内存地址是" << (void* )s1.c_str() << endl;

    String s2(s1);
    cout << "S2:" << s2.c_str() << ", s2中m_psz指向的堆内存地址是" << (void* )s2.c_str() << endl; //调用默认拷贝构造函数，s1,s2堆内存地址一样

    String s3("word");
    cout << "S3:" << s3.c_str() << ", s3中m_psz指向的堆内存地址是" << (void* )s3.c_str() << endl;
    String s4  = s3;
    cout << "S4:" << s4.c_str() << ", s4中m_psz指向的堆内存地址是" << (void* )s4.c_str() << endl;

}