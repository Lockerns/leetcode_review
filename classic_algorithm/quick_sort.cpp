#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int Partition(vector<int>& nums, int left, int right)
{
    int i = left - 1;
    int rand_indice = rand() % (right - left + 1) + left;
    int selected_num = nums[rand_indice];
    swap(nums[rand_indice], nums[right]);
    for (int j = left; j < right; ++j)
    {
        if (nums[j] <= selected_num) swap(nums[++i], nums[j]);
    }
    swap(nums[i + 1], nums[right]);
    return i + 1;
}

void QuickSortProcess(vector<int>& nums, int left, int right)
{
    if (left < right)
    {
        int mid = Partition(nums, left, right);
        int left_mid = mid, right_mid = mid;
        while (left_mid > 0 && nums[left_mid] == nums[left_mid - 1]) --left_mid;
        while (right_mid < nums.size() - 1 && nums[right_mid] == nums[right_mid + 1]) ++right_mid;
        QuickSortProcess(nums, left, mid - 1);
        QuickSortProcess(nums, mid + 1, right);
    }
}
void QuickSort(vector<int>& nums)
{
    QuickSortProcess(nums, 0, nums.size() - 1);
}

int main()
{
    // Seed for random number generator
    std::srand(std::time(0));

    // Create a vector of 30 integers
    std::vector<int> randomNumbers(30);

    // Fill the vector with random numbers
    for (int& num : randomNumbers) {
        num = std::rand() % 1000;
    }

    std::cout << "random:" << std::endl;
    // Optional: Print the vector
    for (const int& num : randomNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    QuickSort(randomNumbers);

    std::cout << "sorted:" << std::endl;
    // Optional: Print the vector
    for (const int& num : randomNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    return 0;
}
