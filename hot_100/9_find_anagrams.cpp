#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.size(), p_len = p.size();
        vector<int> result;
        vector<int> s_count(26, 0);
        vector<int> p_count(26, 0);

        if (s_len < p_len) return result;
        for (int i = 0; i < p_len; ++i)
        {
            p_count[p[i] - 'a']++;
            s_count[s[i] - 'a']++;
        }

        if (p_count == s_count) result.emplace_back(0);

        for (int i = 0; i < s_len - p_len; ++i)
        {
            s_count[s[i] - 'a']--;
            s_count[s[i + p_len] - 'a']++;

            if (s_count == p_count) result.emplace_back(i + 1);
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
