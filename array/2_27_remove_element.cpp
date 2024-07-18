#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int left = 0;
        int right = 0;
        for (int right = 0; right < n; right++)
        {
            if (nums[right] != val)
                nums[left++] = nums[right];
        }
        return left;
    }
};

int main()
{
    Solution solu;
    std::vector<int> nums = {3, 3, 6, 4, 5};
    int result = solu.removeElement(nums, 6);
    cout << result << endl;
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}