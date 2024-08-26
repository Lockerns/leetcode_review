#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = 0;
        int sum = 0;

        int hax = 0, max_num = 0;
        for (int t = 0; t < height.size(); ++t)
        {
            if (height[t] > max_num)
            {
                max_num = height[t];
                hax = t;
            } 
        }
        while (height[i] == 0 && i < hax) i++;
        while (i < hax)
        {
            // if (height[i] != 0 && height[i + 1] != 0) continue;
            while (i < hax && height[i] <= height[i + 1]) i++;
            j = i + 1;
            while(height[j] < height[i] && j <= hax)
            {
                sum += (height[i] - height[j]);
                j++;
            }
            i = j - 1;
        }
        i = height.size() - 1;
        while (i > hax)
        {
            // if (height[i] != 0 && height[i + 1] != 0) continue;
            while (i > hax && height[i] <= height[i - 1]) i--;
            j = i - 1;
            while(height[j] < height[i] && j >= hax)
            {
                sum += (height[i] - height[j]);
                j--;
            }
            i = j + 1;
        }
        return sum;
    }
};

int main()
{
    Solution a;
    vector<int> height = {2, 0, 2};
    int sum = a.trap(height);
    cout << sum << endl;
    return 0;
}