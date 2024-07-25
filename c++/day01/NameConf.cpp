//命名空间可以划分更为精细的逻辑单元，避免出现名字冲突问题
#include <iostream>
namespace ICBC{
    int g_money = 0;

    void save(int money){
        g_money += money;
    }
}


namespace CCB{
    int g_money = 0;
    void save(int money){
        g_money += money;
    }

    void pay(int money);//先声明，可以在命名空间外通过命名空间来定义
}

void CCB::pay(int money){//定义
    g_money -= money;
}


namespace ICBC{//可以多次使用同一命名空间来编写不同的函数或变量，都在一个命名空间中
    void pay(int money){
        g_money -= money;
    }
}

void test01(){
    ICBC::save(1000);
    std::cout << "ICBC银行卡余额为:" << ICBC::g_money << std::endl;
    ICBC::pay(200);
    std::cout << "ICBC银行卡余额为"  << ICBC::g_money << std::endl;

    using namespace std;
    CCB::save(20000);
    cout << "CCB银行卡余额为:" << CCB::g_money << endl;
    CCB::pay(999);
    cout << "CCB银行卡余额为:" << CCB::g_money << endl;
    
}

int main(){
    test01();


}