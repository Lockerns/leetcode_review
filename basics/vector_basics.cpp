#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;

    // 初始状态
    std::cout << "Initial size: " << vec.size() << std::endl;        // 输出: 0
    std::cout << "Initial capacity: " << vec.capacity() << std::endl; // 输出: 0

    // 添加5个元素
    vec.push_back(1);
    std::cout << "After adding 1 elements, size: " << vec.size() << std::endl;        // 输出: 5
    std::cout << "After adding 1 elements, capacity: " << vec.capacity() << std::endl; // 输出: 通常是8（取决于实现，可能有所不同）
    vec.push_back(2);
    std::cout << "After adding 2 elements, size: " << vec.size() << std::endl;        // 输出: 2
    std::cout << "After adding 2 elements, capacity: " << vec.capacity() << std::endl; // 输出: 通常是8（取决于实现，可能有所不同）
    vec.push_back(3);
    std::cout << "After adding 3 elements, size: " << vec.size() << std::endl;        // 输出: 3
    std::cout << "After adding 3 elements, capacity: " << vec.capacity() << std::endl; // 输出: 通常是8（取决于实现，可能有所不同）
    vec.push_back(4);
    std::cout << "After adding 4 elements, size: " << vec.size() << std::endl;        // 输出: 4
    std::cout << "After adding 4 elements, capacity: " << vec.capacity() << std::endl; // 输出: 通常是8（取决于实现，可能有所不同）
    vec.push_back(5);
    std::cout << "After adding 5 elements, size: " << vec.size() << std::endl;        // 输出: 5
    std::cout << "After adding 5 elements, capacity: " << vec.capacity() << std::endl; // 输出: 通常是8（取决于实现，可能有所不同）

    // std::cout << "After adding 5 elements, size: " << vec.size() << std::endl;        // 输出: 5
    // std::cout << "After adding 5 elements, capacity: " << vec.capacity() << std::endl; // 输出: 通常是8（取决于实现，可能有所不同）

    // 使用reserve预留空间
    vec.reserve(20);
    std::cout << "After reserving capacity for 20 elements, size: " << vec.size() << std::endl;        // 输出: 5
    std::cout << "After reserving capacity for 20 elements, capacity: " << vec.capacity() << std::endl; // 输出: 20

    // 使用resize改变大小
    vec.resize(10);
    std::cout << "After resizing to 10 elements, size: " << vec.size() << std::endl;        // 输出: 10
    std::cout << "After resizing to 10 elements, capacity: " << vec.capacity() << std::endl; // 输出: 20

    // 使用resize减少大小
    vec.resize(3);
    std::cout << "After resizing to 3 elements, size: " << vec.size() << std::endl;        // 输出: 3
    std::cout << "After resizing to 3 elements, capacity: " << vec.capacity() << std::endl; // 输出: 20

    return 0;
}