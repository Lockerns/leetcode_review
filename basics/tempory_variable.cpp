#include <iostream>
using namespace std;

class A {
  public:
    A() { cout << "default construct A" << endl; }

    A(const A& other) {
      cout << "copy constructor A" << endl;
    }

    A& operator=(const A& other) {
        cout << "assignment operation A" << endl;
        return *this;
    }

    ~A() { cout << "destruct A" << endl; }
};

class MyClass {
  public:
    MyClass() { cout << "default constructor MyClass" << endl; }

    MyClass(const A& x) : a_(x) { 
        cout << "initializer list constructor MyClass" << endl; }
    
    // The initializer list directly performs the copy constructor.
    // The assignment within parentheses first creates, then performs the assignment operation.

    // MyClass(A x) : a_(x) { 
    //     cout << "intitial list constructor MyClass" << endl; }

    // MyClass(const A& x) { 
    //     a_ = x;
    //     cout << "assignment constructor" << endl; }

    MyClass(const MyClass& other) {
        a_ = other.a_;
        cout << "copy constructor MyClass" << endl;
    }

    MyClass& operator=(const MyClass& other) {
        a_ = other.a_;
        cout << "assignment operation MyClass" << endl;
        return *this;
    }

    ~MyClass() { cout << "destruct MyClass" << endl; }

  private:
    A a_;
};

int main() {
    cout << "___________\n" << endl;
    A a1;
    MyClass t1;
    cout << "___________\n" << endl;
    MyClass t2(a1);
    cout << "___________\n" << endl;
    MyClass t3(t2);
    cout << "___________\n" << endl;
    MyClass t4 = t2;
    cout << "___________\n" << endl;
    MyClass t5 = MyClass(a1);
    cout << "___________\n" << endl;

    // In the line MyClass t5 = MyClass(a1);, 
    // it might appear as though a temporary object of type MyClass is created 
    // and then copied to t5. However, modern C++ compilers typically optimize 
    // this scenario using copy elision or RVO, meaning no temporary object is created, 
    // and t5 is constructed directly using a1.

    return 0;
}