#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(0), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> AllOrderTrace(TreeNode* root)
    {
        stack<TreeNode*> st;
        vector<int> result;
        if (root!= nullptr) st.push(root);

        while(!st.empty())
        {
            TreeNode* node = st.top();
            if (node != nullptr)
            {
                st.pop();
                if (node->right) st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if (node->left) st.push(node->left);
            }
            else
            {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
}

int main()
{
    return 0;
}
