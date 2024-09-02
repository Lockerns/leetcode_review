#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        while (right < nums.size())
        {
            if (nums[left] != 0)
            {
                left++;
            }
            if (nums[right] != 0)
            {
                swap(nums[left], nums[right]);
            }
            right++;
        }
    }
};

int main()
{
    Solution test;
    vector<int> input_test = {0, 1, 0, 3, 12};
    test.moveZeroes(input_test);
    for (auto num : input_test)
    {
        cout << num << ",";
    }
}