#include <iostream>

class MyClass {
public:
    // explicit MyClass(int x) {
    //     value = x;
    //     std::cout << "Integer constructor called" << std::endl;
    // }
    MyClass(int x) {
        value = x;
        std::cout << "Integer constructor called" << std::endl;
    }

    void printValue() {
        std::cout << "Value: " << value << std::endl;
    }

private:
    int value;
};

void process(MyClass obj) {
    obj.printValue();
}

int main() {

    // 编译器在此处会进行隐式转换，把5和'A'转化为 MyClass类型
    // 对于5的转化本身不会导致运行错误，但是对'A'的转化会(期望的运行结果是输出'A'，实际输出65)
    // 加上explicit后，在编译时就会报错，由此避免程序运行错误
    process(5);    // Still calls the MyClass constructor
    process('A');  // Now gives a compilation error - no implicit conversion allowed

    return 0;
}
