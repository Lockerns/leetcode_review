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
        str_ = new char[length_ + 1];
        for (int i = 0; i < length_; ++i) {
            *(str_ + i) = *(s + i);
        }
        *(str_ + length_) = '\0';
        cout << "char* s" << endl;
    }
    MyStr(const MyStr& other) {
        str_ = new char[other.length_ + 1];
        length_ = other.length_;
        for (int i = 0; i < length_; ++i) {
            *(str_ + i) = *(other.str_ + i);
        }
        *(str_ + length_) = '\0';
        cout << "copy" << endl;
    }
    MyStr(MyStr&& other) : str_(other.str_), length_(other.length_) {
        other.str_ = nullptr;
        other.length_ = 0;
        cout << "move" << endl;
    }
    MyStr& operator=(const MyStr& other) {
        if (this == &other) {
            return *this;
        }
        clear();
        str_ = new char[other.length_ + 1];
        length_ = other.length_;
        for (int i = 0; i < length_; ++i) {
            *(str_ + i) = *(other.str_ + i);
        }
        *(str_ + length_) = '\0';
        cout << "assign" << endl;
        return *this;
    }
    ~MyStr() {
        if (str_) {
            clear();
        }
    }

    friend ostream& operator<<(ostream& os, const MyStr& str) {
        if (str.str_) {
            os << str.str_;
            return os;
        } else {
            return os;
        }
    }

    size_t size() {
        return length_;
    }

    void clear() {
        delete[] str_;
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
        MyStr b(a);
        MyStr c = a;
        MyStr d(move(a));

        cout << "a:" << a << endl;
        cout << "b:" << b << endl;
        cout << "c:" << c << endl;
        cout << "d:" << d << endl;
        /*
        default
        char* s
        assign
        copy
        copy
        move
        */
    }

    return 0;
}