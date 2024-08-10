#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

vector<vector<int>> LeverOrder(TreeNode* root)
{
    vector<vector<int>> result;
    if (root == nullptr) return result;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty())
    {
        int length = que.size();
        vector<int> path;
        for (int i = 0; i < length; ++i)
        {
            TreeNode* cur = que.front();
            que.pop();
            path.push_back(cur->val);
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
        result.push_back(path);
    }
    return result;
}
int main()
{
    return 0;
}