#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0, length = nums.size(), min_length = nums.size();
        for (; right < nums.size(); right++)
        {
            sum += nums[right];
            while(sum >= target)
            {
                length = right - left + 1;
                sum -= nums[left++];
            }
            if (length < min_length) min_length = length;
        }
        if (left == 0) return 0;
        return min_length;
    }
};
