#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> TwoSum(vector<int> & nums, int target)
{
    vector<int> result;
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        int index;
        auto it = map.find(target - nums[i]);
        if (it != map.end()) 
        {
            index = it->second;
            result.push_back(index);
            result.push_back(i);
            break;
        }
        else
        {
            map[nums[i]] = i;
        }
    }
    return result;
}
int main()
{
    return 0;
}
