// 命名空间声明
#include <iostream>
using namespace std;

namespace ns{
    int g_value = 0;
}
namespace ns1{
    int g_value = 0;
}
//int g_value = 0;
//using ns::g_value;
int main(void){
    //int g_value = 0;
    using ns::g_value;//ns中的g_value引入当前作用域
    //using ns1::g_value;//两个命名空间引入相同的变量，报错
    g_value = 666;
    cout << "g_value = " << ns::g_value << endl;
    return 0;

}
