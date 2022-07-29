#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CBTInserter 
{

private:

    TreeNode* root;
    queue<TreeNode*> nodeQueue;

public:

    CBTInserter(TreeNode* _root) 
    {
        root = _root;
        nodeQueue.push(root);
    }
    
    int insert(int val) 
    {
        while(nodeQueue.front()->left != nullptr && nodeQueue.front()->right != nullptr)
        {
            nodeQueue.push(nodeQueue.front()->left);
            nodeQueue.push(nodeQueue.front()->right);
            nodeQueue.pop();
        }

        if (nodeQueue.front()->left == nullptr)
        {
            nodeQueue.front()->left = new TreeNode(val);
            return nodeQueue.front()->val;
        }

        if (nodeQueue.front()->right == nullptr)
        {
            nodeQueue.front()->right = new TreeNode(val);
            int fatherVal = nodeQueue.front()->val;
            nodeQueue.push(nodeQueue.front()->left);
            nodeQueue.push(nodeQueue.front()->right);
            nodeQueue.pop();
            return fatherVal;
        }

        return -1;
    }
    
    TreeNode* get_root() 
    {
        return root;
    }

};

int main()
{
    CBTInserter* obj = new CBTInserter(new TreeNode(1, new TreeNode(2), nullptr));

    cout << obj->insert(3) << endl;
    cout << obj->insert(4) << endl;

    TreeNode* node = obj->get_root();

    return 0;
}