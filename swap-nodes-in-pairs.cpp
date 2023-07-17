#include <iostream>
#include "listnode.h"

using namespace std;

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head && head->next)
        {
            ListNode *next = head->next, *nextnext = head->next->next;
            next->next = head;
            head->next = swapPairs(nextnext);
            return next;
        }
        else
        {
            return head;
        }
    }
};

int main()
{
    return 0;
}