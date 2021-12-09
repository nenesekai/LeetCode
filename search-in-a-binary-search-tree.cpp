#include <iostream>
#include "listnode.hpp"

class Solution 
{
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if (root == nullptr)  return nullptr;
        if (root->val == val) return root;

        if (root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};

int main()
{
    Solution solution;

    TreeNode* test_data = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7));

    solution.searchBST(test_data, 2);

    return 0;
}