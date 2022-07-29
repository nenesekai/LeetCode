#include <iostream>
#include <random>
#include <vector>

using namespace std;

constexpr int MAX_LEVEL = 32;

struct SkiplistNode
{
    int val, level;
    vector<SkiplistNode*> next;
    SkiplistNode(int _val, int _level = MAX_LEVEL) : val(_val), level(_level), next(_level, nullptr) {}
};

class Skiplist 
{

private:

    SkiplistNode* head;
    int level = 0;
    mt19937 gen;
    uniform_int_distribution<int> dis;

public:

    Skiplist() : head(new SkiplistNode(-1)), dis(0, 1) {}
    
    bool search(int target) 
    {
        SkiplistNode* curr = head;

        for (int i = level - 1; i >= 0; i--)
        {
            while (curr->next[i] && curr->next[i]->val <= target)
            {
                if (curr->next[i]->val == target) return true;
                curr = curr->next[i];
            }
        }

        return false;
    }
    
    void add(int num) 
    {
        vector<SkiplistNode*> update(MAX_LEVEL, head);
        SkiplistNode* curr = head;

        for (int i = level - 1; i >= 0; i--)
        {
            while (curr->next[i] && curr->next[i]->val < num)
            {
                curr = curr->next[i];
            }

            update[i] = curr;
        }

        int currLevel = genLevel();

        SkiplistNode* newNode = new SkiplistNode(num, currLevel);

        level = max(level, currLevel);

        for (int i = currLevel - 1; i >= 0; i--)
        {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }
    }
    
    bool erase(int num) 
    {
        vector<SkiplistNode*> update(MAX_LEVEL, head);
        SkiplistNode* curr = head;

        for (int i = level - 1; i >= 0; i--)
        {
            while (curr->next[i] && curr->next[i]->val < num)
            {
                curr = curr->next[i];
            }
            
            update[i] = curr;
        }

        // 如果找不到这个num就返回false
        if (curr == nullptr || curr->next[0] == nullptr || curr->next[0]->val != num) return false;

        curr = curr->next[0];

        for (int i = curr->level - 1; i >= 0; i--)
        {
            update[i]->next[i] = curr->next[i];
        }

        delete curr;

        while (head->next[level - 1] == nullptr) level--;

        return true;
    }
    
    // 随机出一个level给新的node

    int genLevel()
    {
        int level = 1;

        while (level < MAX_LEVEL && dis(gen) == 1)
        {
            level++;
        }

        return level;
    }

};

int main()
{
    Skiplist* obj = new Skiplist();
    obj->add(9);
    obj->add(4);
    obj->add(5);
    obj->add(6);
    obj->add(9);
    cout << obj->erase(2) << endl;
    cout << obj->erase(1) << endl;
    obj->add(2);
    cout << obj->search(7) << endl;
    cout << obj->search(4) << endl;
    obj->add(5);
    cout << obj->erase(6) << endl;
    cout << obj->search(5) << endl;
    obj->add(6);
    obj->add(7);
    obj->add(4);
    cout << obj->erase(3) << endl;
    cout << obj->search(6) << endl;
    cout << obj->erase(3) << endl;
    cout << obj->search(4) << endl;
    cout << obj->search(3) << endl;
    cout << obj->search(8) << endl;
    cout << obj->erase(7) << endl;
    cout << obj->erase(6) << endl;
    cout << obj->search(7) << endl;
    cout << obj->erase(4) << endl;
    obj->add(1);
    obj->add(6);
    cout << obj->erase(3) << endl;
    obj->add(4);
    cout << obj->search(7) << endl;
    cout << obj->search(6) << endl;
    cout << obj->search(1) << endl;
    cout << obj->search(0) << endl;
    cout << obj->search(3) << endl;

    return 0;
}