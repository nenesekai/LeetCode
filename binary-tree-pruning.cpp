#include <iostream>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{

public:

    TreeNode* pruneTree(TreeNode* root) 
    {
        if (root == nullptr) return nullptr;

    }

    void cut(TreeNode* node)
    {
        if (node->val == 0 && node->left == nullptr && node->right == nullptr) node = nullptr;
    }

};

int main()
{
    TreeNode* example = new TreeNode(1, nullptr, new TreeNode(0, new TreeNode(0), new TreeNode(1)));

    Solution* obj = new Solution;

    TreeNode* result = obj->pruneTree(example);

    return 0;
}