#include <iostream>
using namespace std;

template<typename T>
class MySharedPtr {
  public:
    explicit MySharedPtr(T* ptr = nullptr) : ptr_(ptr), count_(ptr ? new int(1) : nullptr) {
        cout << "MySharedPtr constructor 1" << endl;
    }

    MySharedPtr(const MySharedPtr& other) : ptr_(other.ptr_), count_(other.count_) {
        if (count_) {
            ++(*count_);
        }
        cout << "MySharedPtr constructor 2" << endl;
    }

    MySharedPtr& operator=(const MySharedPtr& other) {
        if (this != &other) {
            release();
            ptr_ = other.ptr_;
            count_ = other.count_;
            if (count_) {
                ++(*count_);
            }
        }
        return *this;
    }

    virtual ~MySharedPtr() {
        release();
        cout << "MySharedPtr destructor" << endl;
    }

    T& operator*() const { return *ptr_; }
    T* operator->() const { return *ptr_; }
    T* get() const { return ptr_; }

    int use_count() const {
        if (count_) {
            return *count_;
        }
        else {
            return 0;
        }
    }

  private:
    T* ptr_;
    int* count_;

    void release() {
        if (count_ && --count_ == 0) {
            delete ptr_;
            delete count_;
            cout << "Release memory" << endl;
        }
        ptr_ = nullptr;
        count_ = nullptr;
    }
};

class MyClass {
  public:
    MyClass() { cout << "MyClass constructor" << endl; }
    ~MyClass() { cout << "MyClass deconstructor" << endl; }
    void DoSomething() { cout << "Do something" << endl; }
};

int main()
{
    MySharedPtr<MyClass> ptr1(new MyClass());

    // MySharedPtr<MyClass> ptr2(ptr1);
    {
        // MySharedPtr<MyClass> ptr2 = ptr1;
    }
    return 0;
}