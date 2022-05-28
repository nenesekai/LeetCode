#include <iostream>
#include <vector>

using namespace std;

class Node
{

public:

    int val;
    vector<Node*> children;

    Node() {}

    Node(int val) : val(val) {}

    Node(int val, vector<Node*> children) : val(val), children(children) {}
    
};

class Solution
{

public:

    vector<vector<int>> rt;
    vector<Node*> last, previous;

    bool stop = false;

    void add_rt()
    {
        last = previous;

        previous.clear();

        stop = true;
        
        vector<int> new_rt;

        for (Node* node : last)
        {

            for (Node* children : node->children)
            {
                new_rt.push_back(children->val);
                previous.push_back(children);

                if (children->children.size() != 0) stop = false;
            }
        }

        if (!new_rt.empty()) rt.push_back(new_rt);

        if (!stop) add_rt();
    }

    vector<vector<int>> levelOrder(Node* root)
    {
        if (root == nullptr) return {};

        previous.push_back(root);
        rt.push_back(vector<int>{root->val});

        add_rt();

        return rt;
    }

};

int main()
{
    Node* root = new Node(1, {new Node(3, {new Node(5), new Node(6)}), new Node(2), new Node(4)});

    Node* root2 = new Node(44);

    Solution solution;

    vector<vector<int>> result = solution.levelOrder(root2);

    for (vector<int> nums : result)
    {
        for (int num : nums)
        {
            cout << num << " ";
        }

        cout << endl;
    }

    return 0;
}