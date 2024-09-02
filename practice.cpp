#include <iostream>

using namespace std;

class MyStack {
  public:
    MyStack() {
        capacity_ = 2;
        arr_ = new int(capacity_);
        top_indice_ = -1;
    }

    ~MyStack() {
        delete arr_;
    }

    void push(int value) {
        if (++top_indice_ > capacity_) {
            resize(capacity_ * 2);
        }
        arr_[top_indice_] = value;
    }

    int pop() {
        return arr_[top_indice_--];
    }

    int top() {
        return arr_[top_indice_];
    }

    int size() {
        return top_indice_ + 1;
    }

    bool is_empty() {
        return top_indice_ == -1;
    }

  private:
    int* arr_;
    int top_indice_;
    int capacity_;
    void resize(int new_capacity) {
        int* new_arr = new int(new_capacity);
        for (int i = 0; i < top_indice_; ++i) {
            new_arr[i] = arr_[i];
        }
        delete arr_;
        arr_ = new_arr;
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