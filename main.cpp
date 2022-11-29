#include <iostream>

using namespace std;

// TODO: add a queue of index and change `pop()`

struct ListNode
{
    int val, freq;
    ListNode* next;

    ListNode() : val(0), freq(1), next(nullptr) {}
    ListNode(int val) : val(val), freq(1), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), freq(1), next(next) {}
};

class FreqStack
{
private:
    ListNode* head;
public:
    FreqStack() : head(nullptr) {}

    void push(int val)
    {
        if (!head)
        {
            head = new ListNode(val);
            return;
        }

        ListNode* node = head;

        if (node->val == val)
        {
            node->freq++;
            return;
        }

        while (node->next)
        {
            if (node->next->val == val)
            {
                node->next->freq++;
                return;
            }
            else
            {
                node = node->next;
            }
        }

        node->next = new ListNode(val);
    }

    int pop()
    {
        if (!head) return -1;

        if (!head->next) 
        {
            int val = head->val;
            delete head;
            head = nullptr;
            return val;
        }

        ListNode* temp = new ListNode(-1, head);

        ListNode* curr = temp;
        ListNode* max = temp;

        if (curr->next)
        {
            if (curr->next->freq > max->next->freq)
            {
                max = curr;
            }
        }

        int val;

        if (curr == temp)
        {
            val = head->val;
            head = head->next;
            delete temp->next;
        }
        else
        {
            val = max->next->val;
            ListNode* tbd = max->next;
            max->next = max->next->next;
            delete tbd;
        }

        delete temp;
        return val;
    }

    void print_all()
    {
        ListNode* curr = head;

        while (curr)
        {
            cout << "Val: " << curr->val << endl;
            cout << "Freq: " << curr->freq << endl;
            cout << "=========================" << endl;

            curr = curr->next;
        }
    }
}; 

int main()
{
    int usr;

    FreqStack* fs = new FreqStack();

    cout << "1: push; 2: pop; 3: debug; 0: exit" << endl;
    while (cin >> usr)
    {
        if (usr == 1)
        {
            int val;
            cin >> val;
            fs->push(val);
        }
        else if (usr == 2)
        {
            cout << fs->pop();
        }
        else if (usr == 3)
        {
            fs->print_all();
        }
        else
        {
            break;
        }
    }

    return 0;
}
