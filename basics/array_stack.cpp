#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;          // 用于存储栈元素的数组
    int topIndex;      // 指向栈顶元素的索引
    int capacity;      // 栈的当前容量

    // 私有方法，用于扩容数组
    void resize(int newCapacity) {
        int* newArr = new int[newCapacity];
        for (int i = 0; i <= topIndex; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    // 构造函数，初始化栈
    Stack() {
        capacity = 2;    // 初始容量
        arr = new int[capacity];
        topIndex = -1;   // 初始化栈为空
    }

    // 析构函数，释放动态分配的内存
    ~Stack() {
        delete[] arr;
    }

    // 入栈操作
    void push(int value) {
        if (topIndex == capacity - 1) {
            resize(capacity * 2);  // 容量不够时，扩展为原来的两倍
        }
        arr[++topIndex] = value;
    }

    // 出栈操作
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow. Cannot pop from the stack.\n";
            return -1; // 可以根据需求返回其他值
        }
        int value = arr[topIndex--];
        
        // 缩小容量，如果栈中的元素数目小于容量的四分之一
        if (topIndex + 1 <= capacity / 4 && capacity > 2) {
            resize(capacity / 2);
        }
        
        return value;
    }

    // 查看栈顶元素
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element.\n";
            return -1; // 可以根据需求返回其他值
        }
        return arr[topIndex];
    }

    // 判断栈是否为空
    bool isEmpty() {
        return topIndex == -1;
    }

    // 返回栈的大小
    int size() {
        return topIndex + 1;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.top() << endl;

    stack.pop();
    cout << "Top element after pop is: " << stack.top() << endl;

    cout << "Stack size is: " << stack.size() << endl;

    return 0;
}
