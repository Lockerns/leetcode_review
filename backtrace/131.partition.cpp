#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
private:
    vector<string> path;
    vector<vector<string>> results;
    bool is_hui(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
    void backtracing(string s, int index)
    {
        if (!path.empty() && !is_hui(path.back()))
            return;
        if (index >= s.size())
        {
            results.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            string tmp = s.substr(index, i + 1 - index);
            path.push_back(tmp);
            backtracing(s, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        backtracing(s, 0);
        return results;
    }
};

int main()
{
    Solution s;
    string s1 = "aab";
    vector<vector<string>> res = s.partition(s1);
    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}