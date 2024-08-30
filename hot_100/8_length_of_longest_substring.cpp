#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> past;
        int n = s.size();

        int right = 0, result = 0;

        for (int i = 0; i < n; ++i)
        {
            if (i != 0) past.erase(s[i - 1]);
            while (right < n && !past.count(s[right]))
            {
                past.insert(s[right]);
                right++;
            }
            result = max(result, right - i);
        }
        return result;
    }
};

int main()
{
    Solution a;
    string s = "abcabcbb";
    int sum = a.lengthOfLongestSubstring(s);
    cout << sum << endl;
    return 0;
}
