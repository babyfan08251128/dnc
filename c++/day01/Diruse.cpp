//命名空间指令
#include <iostream>
using namespace std;

namespace ns{
    int g_value = 0;    
}
using namespace std;
int main(){
    //using namespace ns;
    int g_value = 0;
    g_value = 666;
    cout << "ns::g_value = " << ns::g_value << endl;
    return 0;

}