#include <iostream>
using namespace std;

class MyStack {
  public:
    MyStack() {
        capacity_ = 2;
        top_index_ = -1;
        arr_ = new int[capacity_];
    }

    virtual ~MyStack() {
        delete[] arr_;
    }

    void push(int val) {
        if (top_index_ == capacity_ - 1) {
            resize(capacity_ * 2);
        }
        arr_[++top_index_] = val;
    }

    int top() {
        if (is_empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr_[top_index_];
    }

    int pop() {
        if (is_empty()) {
            cout << "Stack underflow." << endl;
            return -1;
        }
        return arr_[top_index_--];
    }

    bool is_empty() {
        return top_index_ == -1;
    }

    int size() {
        return top_index_ + 1;
    }

  private:
    int* arr_;
    int top_index_;
    int capacity_;

    void resize(int new_capacity) {
        int* new_arr = new int[new_capacity];
        for (int i = 0; i <= top_index_; ++i) {
            new_arr[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = new_arr;
        capacity_ = new_capacity;
    }
};

int main() {
    MyStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.top() << endl;

    stack.pop();
    cout << "Top element after pop is: " << stack.top() << endl;

    cout << "Stack size is: " << stack.size() << endl;

    return 0;
}