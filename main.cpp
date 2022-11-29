#include <iostream>
#include <stack>

using namespace std;

struct ListNode
{
    int val, freq;
    ListNode* next;

    ListNode() : val(0), next(nullptr), freq(0) {}
    ListNode(int val) : val(val), next(nullptr), freq(0) {}
    ListNode(int val, ListNode* next) : val(val), next(next), freq(0) {}
};

class FreqStack
{
private:
    ListNode* head;
public:
    FreqStack()
    {
        head = nullptr;
    }

    void push(int val)
    {
        if (!head) 
        {
            head = new ListNode(val);
            return;
        }

        while (head->next)
        {
            if (head->val == val)
            {
                head->freq++;
                return;
            }
            else
            {
                head = head->next;
            }
        }
    }

    int pop()
    {

    }
};

int main()
{
    FreqStack fs;

    return 0;
}
