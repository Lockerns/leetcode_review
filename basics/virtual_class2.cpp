#include <iostream>
using namespace std;

class A {
public:
    virtual void funPrint() {
        cout << "funPrint of class A" << endl;
    }
};

class B : public A {
public:
    void funPrint () override {
        cout << "funPrint of class B" << endl;
    }
};

int main() {
    A *p;  // 定义基类的指针
    A a;
    B b;

    p = &a;
    p->funPrint();  // 输出: funPrint of class A

    p = &b;
    p->funPrint();  // 输出: funPrint of class A

    return 0;
}