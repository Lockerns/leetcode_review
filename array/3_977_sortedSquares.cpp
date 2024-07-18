#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if(nums[right]*nums[right] > nums[left]*nums[left])
                result[i] = nums[right]*nums[right--];
            else
                result[i] = nums[left]*nums[left++];
        }
        return result;
    }
};

int main()
{
    Solution solu;
    std::vector<int> nums = {-4,-1,0,3,10};
    vector<int> result;
    cout << "test" << endl;
    result = solu.sortedSquares(nums);
    // cout << result << endl;
    for (int num : result)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
