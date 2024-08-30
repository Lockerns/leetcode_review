#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;

        while (left < right)
        {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);

            if (height[left] < height[right])
            {
                result += left_max - height[left];
                left++;
            }
            else
            {
                result += right_max - height[right];
                right--;
            }
        }
        return result;
    }
};

int main()
{
    Solution a;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int sum = a.trap(height);
    cout << sum << endl;
    return 0;
}
