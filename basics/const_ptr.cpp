#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
    // 指针常量, 可以改变指向，但不能修改指向对象的值
    int a = 1;
    int b = 3;
    int const *p;
    p = &a;
    cout << *p << endl;
    a = 2;
    cout << *p << endl;
    p = &b;
    cout << *p << endl;
    // *p = 3;  // 报错
    // cout << *p << endl;

    // 常量指针，可以修改指向对象的值，但是不能修改指向
    int *const q = &b;
    // q = &a;  // 不能修改指向
    *q = 4;
    cout << *p << endl;
    return 0;
  }
