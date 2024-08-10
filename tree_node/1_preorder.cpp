#include <iostream>
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

class Solution
{
public:
    vector<int> result;
    void Tracing(TreeNode* root)
    {
        if (root == nullptr) return;
        result.push_back(root->val);
        Tracing(root->left);
        Tracing(root->right);
    }
    vector<int> PreorderTrace(TreeNode* root)
    {
        Tracing(root);
        return result;
    }
};

int main()
{

}