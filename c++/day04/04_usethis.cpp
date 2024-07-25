//常对象(被const修饰的对象，指针和引用)和非常对象(没有被const修饰的对象，指针，引用)
//常函数(编译器补的this参数有const修饰)和非常函数(编译器补的this参数没有const修饰)
# include <iostream>
# include <cstring>
using namespace std;

class Integer{
public:
    
    void SetInfo(int i){//非常函数
        m_i = i;
    }
    
    void GetInfo(){
        cout << "非常函数GetInfo:" << m_i << endl;
    }

    void GetInfo()const{
        //this->m_i = 666;//不能在常函数内修改非mutable的成员变量
        this->m_i = 666;
        cout << "常函数:" << m_i << endl;
    }
private:
    mutable int m_i;
};

int main(void){
    Integer ix;//ix是常对象
    Integer* pix = &ix;//pix是常对象，指针
    Integer& rix = ix;//rix是常对象，引用

    ix.SetInfo(1000);
    ix.GetInfo();//有非常函数先调用非常函数，没有非常函数调用常函数，非常函数优于常函数

    const Integer cix = ix;//常对象
    const Integer* pcix = &ix;//常对象
    const Integer& rcix = ix;//常对象
    //cix.SetInfo(100);       只能调用常函数
    cix.GetInfo();


    



}
