#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::vector<std::vector<std::string>> res_strs;
        std::unordered_map<std::string, int> mp;
        int groups = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            std::string res_s = strs[i];
            std::sort(res_s.begin(), res_s.end());
            auto it = mp.find(res_s);
            if (it != mp.end())
            {
                res_strs[it->second].push_back(strs[i]);
            }
            else
            {
                mp[res_s] = groups;
                groups++;
                std::vector<std::string> res_vs;
                res_vs.push_back(strs[i]);
                res_strs.push_back(res_vs);
            }
        }
        return res_strs;
    }
};

int main()
{
    Solution solu;
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> res_strs;
    res_strs = solu.groupAnagrams(strs);
    for (int i = 0; i < res_strs.size(); i++)
    {
        std::cout << "[";
        for (int j = 0; j < res_strs[i].size(); j++)
        {
            std::cout << "\"" << res_strs[i][j] << "\"";
            if (j < res_strs[i].size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}