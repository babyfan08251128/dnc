//引用型返回值
# include <iostream>
using namespace std;

int g_value = 0;

int& fun(){ // 非常引用型返回值，通过返回值可以修改目标
    return g_value;
}

const int& func(){
    return g_value;
}
int& bar(){
    static int s_value = 0;
    cout << "s_value = " << s_value << endl;
    return s_value;
}

int& hum(){
    int* p = new int; 
    return *p;
}

int& foo(int& x){//传入一个参数，返回这个参数
    return x;
}


int main(){
    fun() = 100;
    cout << "g_value = " << g_value << endl;

    //func() = 100;//表达式必须是可修改的左值

    bar() = 200;
    bar();
    bar() = 300;
    bar();

    int& result = hum();
    result = 400;
    cout << "p" << hum() << endl;
    delete &result;

    int a_value = 0;
    foo(a_value) = 400;
    cout << "a_value = " << a_value << endl;

    return 0;
}