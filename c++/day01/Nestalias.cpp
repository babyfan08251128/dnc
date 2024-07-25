//命名空间嵌套
#include <iostream>
using namespace std;

namespace ns1{
    int g_value = 1;
    namespace ns2{
        int g_value = 2;
        namespace ns3{
            int g_value = 3;
            namespace ns4{
                int g_value = 4;
            }
        }
    }
}

int main(void){
    namespace ns_four = ns1::ns2::ns3::ns4;
    cout << "ns_four = " << ns_four::g_value << endl;
    cout << "ns1 = " << ns1::g_value << endl;
    cout << "ns2 = " << ns1::ns2::g_value << endl;
    cout << "ns3 = " << ns1::ns2::ns3::g_value << endl;

}