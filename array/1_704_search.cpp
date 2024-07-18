// 二分查找
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0;
        int right = nums.size();  //***
        while(right > left)
        {
            int middle = (left + right) / 2;  //***
            if (nums[middle] == target) return middle;
            if(nums[middle] > target) right = middle;
            else left = middle + 1;  //***
        }
        return -1;
    }
};
