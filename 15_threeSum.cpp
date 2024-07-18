#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // {-4, -1, -1, 0, 1, 2}
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                for (int k = nums.size() - 1; k > j; k--)
                {
                    if (k < nums.size() - 1 && nums[k] == nums[k + 1])
                        continue;
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> res;
                        res.push_back(nums[i]);
                        res.push_back(nums[j]);
                        res.push_back(nums[k]);
                        result.push_back(res);
                    }
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution test;
    vector<int> input_test = {0, 0, 0, 0};
    // for (auto num : input_test)
    // {
    //     cout << num << ",";
    // }
    vector<vector<int>> result;
    result = test.threeSum(input_test);

    cout << "[";
    for (auto list : result)
    {
        cout << "[";
        for (auto num : list)
            cout << num << ",";
        cout << "],";
    }
    cout << "]";
}