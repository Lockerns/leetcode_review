#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    unordered_set<int> results;
    unordered_set<int> nums_set(nums1.begin(), nums2.end());
    for (auto& ele : nums2)
    {
        if (nums_set.find(ele) != nums_set.end())
            results.insert(ele);
    }
    return results;
}

int main()
{
    return 0;
}
