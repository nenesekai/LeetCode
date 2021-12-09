#include <iostream>
#include "listnode.hpp"

using namespace std;

class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* delete_ptr = new ListNode(-1, head), *ptr = head;

        for (int i = 0; i < n - 1; i++)
        {
            ptr = ptr->next;
        }

        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
            delete_ptr = delete_ptr->next;
        }

        delete_ptr->next = delete_ptr->next->next;

        if (delete_ptr->val == -1) return delete_ptr->next; else return head;
    }
};

int main()
{
    return 0;
}