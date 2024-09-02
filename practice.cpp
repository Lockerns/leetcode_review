#include <iostream>

using namespace std;

template<typename T>
class MySharedPtr {
  public:
    // explicit MySharedPtr() : ptr_(nullptr), count_(nullptr) {}
    explicit MySharedPtr(T* ptr) : ptr_(ptr), count_(ptr ? new int(1) : nullptr) {}
    MySharedPtr(const MySharedPtr& other) {
        if (other.ptr_) {
            ptr_ = other.ptr_;
            count_ = other.count_;
            if (count_) {
                ++(*count_);
            }
        }
    }
    MySharedPtr& operator=(const MySharedPtr& other) {
        release();
        if (other.ptr_) {
            ptr_ = other.ptr_;
            count_ = other.count_;
            if (count_) {
                ++(*count_);
            }
        }
        return *this;
    }

    ~MySharedPtr() {
        release();
    }

    T& operator*() { return *ptr_; }
    T* operator->() { return ptr_: }
    T* get() const { return ptr_; }
    int use_count() { return count_ ? *count_ : 0; }

  private:
    T* ptr_;
    int* count_;
    void release() {
        delete ptr_;
        delete count_;
        ptr_ = nullptr;
        count_ = nullptr;
    }
};
int main() {
    return 0;
}