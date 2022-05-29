#include <iostream>

using namespace std;

struct TreeNode
{
    int val;

    TreeNode* left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{

public:

    int sum;

    int sumRootToLeaf(TreeNode* root) 
    {
        sum = 0;

        nodeIter(root, "");

        return sum;
    }

    void nodeIter(TreeNode* node, string num)
    {
        num += to_string(node->val);

        if (node->left == nullptr && node->right == nullptr)
        {
            sum += stoi(num, nullptr, 2);
        }   
        else
        {
            if (node->left != nullptr) nodeIter(node->left, num);
            if (node->right != nullptr) nodeIter(node->right, num);
        }
    }

};

int main()
{
    TreeNode* node = new TreeNode(1, new TreeNode(0, new TreeNode(0), new TreeNode(1)), new TreeNode(1, new TreeNode(0), new TreeNode(1)));

    Solution* obj = new Solution();

    cout << obj->sumRootToLeaf(node) << endl;

    return 0;
}