#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>

using namespace std;

class NumArray
{

private:

    vector<int> nums;

    class TreeNode
    {

    public:

        int sum;
        int left, right;

        TreeNode* left_node;
        TreeNode* right_node;

        TreeNode() {};
        TreeNode(int left, int right) : left(left), right(right) {};

    };

    TreeNode* root;

    void build_tree(TreeNode* node, int left, int right)
    {
        node->left = left;
        node->right = right;

        if (left == right)
        {
            node->sum = nums[left];
        }
        else
        {
            int mid = left + (right - left) / 2;

            node->left_node = new TreeNode();
            node->right_node = new TreeNode();

            build_tree(node->left_node, left, mid);
            build_tree(node->right_node, mid + 1, right);

            node->sum = node->left_node->sum + node->right_node->sum;
        }
    }

    void update(TreeNode* node, int index, int val)
    {
        int mid = node->left + (node->right - node->left) / 2;

        if (node->left == node->right)
        {
            node->sum = val;
            return;
        }
        else if (index <= mid)
        {
            update(node->left_node, index, val);
        }
        else if (mid < index)
        {
            update(node->right_node, index, val);
        }

        node->sum = node->left_node->sum + node->right_node->sum;
    }

    int query(TreeNode* node, int left, int right)
    {
        int mid = node->left + (node->right - node->left) / 2;

        if (node->left == left && node->right == right)
        {
            return node->sum;
        }
        else if (right <= mid)
        {
            return query(node->left_node, left, right);
        }
        else if (mid < left)
        {
            return query(node->right_node, left, right);
        }
        else
        {
            return query(node->left_node, left, mid) + query(node->right_node, mid + 1, right);
        }
    }

public:

    NumArray(vector<int>& nums) : nums(nums)
    {
        root = new TreeNode();

        build_tree(root, 0, nums.size() - 1);
    }

    void update(int index, int val)
    {
        update(root, index, val);
    }

    int sumRange(int left, int right)
    {
        return query(root, left, right);
    }

};

int main()
{
    vector<int> nums = {0, 9, 5, 7, 3};

    NumArray* obj = new NumArray(nums);

    cout << obj->sumRange(4, 4) << endl;
    cout << obj->sumRange(2, 4) << endl;
    cout << obj->sumRange(3, 3) << endl;

    obj->update(4, 5);
    obj->update(1, 7);
    obj->update(0, 8);
    cout << obj->sumRange(1, 2) << endl;
    obj->update(1, 9);
    cout << obj->sumRange(4, 4) << endl;
    obj->update(3, 4);

    return 0;
}