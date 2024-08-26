#include <iostream>
#include <vector>
#include <queue>

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

class Solution
{
public:
    vector<int> RightSideView(TreeNode* root)
    {
        vector<int> result;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; ++i)
            {
               TreeNode* node = que.front();
               que.pop();
               if (node->left) que.push(node->left);
               if (node->right) que.push(node->right);
               if (i == (size - 1)) result.push_back(node->val);
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
