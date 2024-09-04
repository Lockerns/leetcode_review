/* 左值（L-value）: “Left value”，表示可以位于赋值运算符左边的表达式。左值通常是
有名字的、持久存在的内存位置，它可以被取地址

右值（R-value）: “Right value”，表示只能位于赋值运算符右边的表达式。右值通常是临时对象
或字面量，它们没有存储地址，或者即使有地址，它们的存在是临时的。
不过，右值引用（introduced in C++11）允许你捕获并操作右值。
*/

#include <iostream>
#include <cstring>

using namespace std;

class MyStr {
  public:
    MyStr() : str_(nullptr), length_(0) { 
        cout << "default" << endl; }
    // MyStr(char* s) : str_(s), length_(s ? strlen(s) : 0) {}
    MyStr(const char* s) {
        length_ = strlen(s);
        str_ = new char[length_];
        for (int i = 0; i < length_; ++i) {
            *(str_ + i) = *(s + i);
        }
        cout << "char* s" << endl;
    }
    MyStr(const MyStr& other) {
        str_ = new char[other.length_];
        length_ = other.length_;
        for (int i = 0; i < length_; ++i) {
            *(str_ + i) = *(other.str_ + i);
        }
        cout << "copy" << endl;
    }
    MyStr(MyStr&& other) : str_(other.str_), length_(other.length_) {
        other.str_ = nullptr;
        other.length_ = 0;
        cout << "move" << endl;
    }
    MyStr& operator=(const MyStr& other) {
        str_ = new char[other.length_];
        length_ = other.length_;
        for (int i = 0; i < length_; ++i) {
            *(str_ + i) = *(other.str_ + i);
        }
        cout << "assign" << endl;
        return *this;
    }
    ~MyStr() {
        if (str_) {
            clear();
        }
    }

    void print() {
        for (int i = 0; i < length_; ++i) {
            cout << *(str_ + i);
        }
        cout << endl;
    }

    size_t size() {
        return length_;
    }

    void clear() {
        delete str_;
        str_ = nullptr;
        length_ = 0;
    }

  private:
    char* str_;
    size_t length_;
};

int main() {

    if (false) {
        int* ptr;
        int x = 10; // x 是左值
        int& ref = x;
        ptr = &ref; // 左值和左值引用可以取地址
        ++(*ptr);
        cout << *ptr << endl; // 11
        cout << ref << endl; // 11

        // 右值引用也可以取地址
        int&& y = std::move(x);
        ++y;
        int* ptr1 = &y;
        ++(*ptr1);
        cout << *ptr << endl; // 13

        int&& r_ref = 3 + 5;
        cout << r_ref << endl;
        ptr1 = &r_ref;
        ++(*ptr1);
        cout << r_ref << endl;
    }

    if (true) {
        MyStr a;
        a = "123";
        cout << "*******" << endl;
        MyStr b(a);
        MyStr c = a;
        MyStr d(move(a));
        a.print();
        cout << "a length: " << a.size() << endl;
        b.print();
        cout << "b length: " << b.size() << endl;
        c.print();
        cout << "c length: " << c.size() << endl;
        d.print();
        cout << "d length: " << d.size() << endl;

        /*
        default
        assign
        copy
        copy
        move
        */
    }

    return 0;
}