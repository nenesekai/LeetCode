#include <iostream>
<<<<<<< HEAD
#include <stack>

using namespace std;

=======

using namespace std;

// TODO: add a queue of index and change `pop()`

>>>>>>> 8b2a055a53b9a8eeff5ff1f6f8d73b117dcabc87
struct ListNode
{
    int val, freq;
    ListNode* next;

<<<<<<< HEAD
    ListNode() : val(0), next(nullptr), freq(0) {}
    ListNode(int val) : val(val), next(nullptr), freq(0) {}
    ListNode(int val, ListNode* next) : val(val), next(next), freq(0) {}
=======
    ListNode() : val(0), freq(1), next(nullptr) {}
    ListNode(int val) : val(val), freq(1), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), freq(1), next(next) {}
>>>>>>> 8b2a055a53b9a8eeff5ff1f6f8d73b117dcabc87
};

class FreqStack
{
private:
    ListNode* head;
public:
<<<<<<< HEAD
    FreqStack()
    {
        head = nullptr;
    }

    void push(int val)
    {
        if (!head) 
=======
    FreqStack() : head(nullptr) {}

    void push(int val)
    {
        if (!head)
>>>>>>> 8b2a055a53b9a8eeff5ff1f6f8d73b117dcabc87
        {
            head = new ListNode(val);
            return;
        }

<<<<<<< HEAD
        while (head->next)
        {
            if (head->val == val)
            {
                head->freq++;
=======
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
>>>>>>> 8b2a055a53b9a8eeff5ff1f6f8d73b117dcabc87
                return;
            }
            else
            {
<<<<<<< HEAD
                head = head->next;
            }
        }
=======
                node = node->next;
            }
        }

        node->next = new ListNode(val);
>>>>>>> 8b2a055a53b9a8eeff5ff1f6f8d73b117dcabc87
    }

    int pop()
    {
<<<<<<< HEAD

    }
};

int main()
{
    FreqStack fs;
=======
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
>>>>>>> 8b2a055a53b9a8eeff5ff1f6f8d73b117dcabc87

    return 0;
}
