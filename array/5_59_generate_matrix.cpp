#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int loop = n / 2;
        int mid = n / 2;
        int start_x = 0, start_y = 0;
        int offset = 1;
        int count = 1;
        int i, j;
        while(loop--)
        {
            i = start_x;
            j = start_y;

            for (; j < n - offset; j++)
            {
                result[i][j] = count++;
            }
            
            for (; i < n - offset; i++)
            {
                result[i][j] = count++;
            }

            for (; j > start_y; j--)
            {
                result[i][j] = count++;
            }

            for (; i > start_x; i--)
            {
                result[i][j] = count++;
            }
            start_x++;
            start_y++;
            offset++;
        }
        if (n % 2 != 0) result[mid][mid] = count;
        return result;
    }
};
