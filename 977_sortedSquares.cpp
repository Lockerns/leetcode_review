#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        vector<int> result;
	    while(right >= left)
        {
            if (nums[left] * nums[left] > nums[right] * nums[right])
            {
                result.push_back(nums[left]*nums[left++]);
            }
            else
                result.push_back(nums[right]*nums[right--]);
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
