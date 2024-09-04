#include <iostream>

using namespace std;

// 引用和指针为有效重载
// const和非const也为有效重载
// 注意：此处不可导入const类型变量
void foo(int& a) {
    cout << "Reference version" << endl;
}

void foo(const int& a) {
    cout << "Const reference version" << endl;
}

void foo(int* a) {
    cout << "Pointer version" << endl;
}

// 返回值不同为无效重载
int foo1(int a) {
    return a;
}

// 此处报错
// double foo1(int a) {
//     return a * 1.0;
// }

int main() {
    int a = 1;
    const int& c = a;

    foo(a);
    foo(&a);
    foo(c);

    return 0;
}