#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[2];
        dp[0] = 0;
        dp[1] = 0;
        int sum = 0;
        for (int i = 2; i <= cost.size(); i++)
        {
            sum = min(dp[0] + cost[i - 2], dp[1] + cost[i - 1]);
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return sum;
    }
};

int main() {
    Solution solution;
    vector<int> cost = {0, 2, 2, 1};
    int result = solution.minCostClimbingStairs(cost);
    cout << "The minimum cost to climb the stairs is: " << result << endl;
    return 0;
}

