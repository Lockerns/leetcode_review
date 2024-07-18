#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> num_set;
        int max = 0;
        for (const int &num : nums)
        {
            num_set.insert(num);
        }
        for (const int &num : nums)
        {
            if (!num_set.count(num - 1))
            {
                int current_num = num;
                int current_streak = 1;
                while (num_set.count(current_num + 1))
                {
                    current_num += 1;
                    current_streak += 1;
                }
                if (current_streak >= max)
                    max = current_streak;
            }
        }
        return max;
    }
};

int main()
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    Solution solu;
    cout << solu.longestConsecutive(nums) << endl;
    return 0;
}