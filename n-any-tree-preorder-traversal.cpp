#include <iostream>
#include <vector>

using namespace std;

class Node
{

public:

    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node*> _children)
    {
        val = _val;
        children = _children;
    }

};

class Solution
{
    
public:

    vector<int> preorder(Node* root, vector<int>* vec = new vector<int>{})
    {
        vec->push_back(root->val);

        for (Node* node: root->children)
        {
            preorder(node, vec);
        }

        return *vec;
    }

};

int main()
{
    Node* test_data = new Node(1, vector<Node*>{new Node(3, vector<Node*>{new Node(5), new Node(6)}), new Node(2), new Node(4)});
    Solution solution;

    vector<int> result = solution.preorder(test_data);

    for (int num: result)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}