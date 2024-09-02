#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> hash_table;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = hash_table.find(target - nums[i]);
            if (it != hash_table.end())
            {
                return {it->second, i};
            }
            else
                hash_table[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    Solution solu;
    std::vector<int> nums = {3, 3};
    std::vector<int> result = solu.twoSum(nums, 6);
    for (int num : result)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}