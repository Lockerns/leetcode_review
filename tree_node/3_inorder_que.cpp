#include <iostream>
#include <stack>
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

vector<int> InorderTrace(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> st;
    if (root == nullptr) return result;
    // st.push(root);
    TreeNode* cur = root;
    while(cur != nullptr || !st.empty())
    {
        if (cur != nullptr)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
    }
    return result;
}
int main()
{
    return 0;
}