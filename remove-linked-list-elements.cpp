#include <iostream>
#include "listnode.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* listnode = head;
        while (listnode != nullptr && listnode->val == val) listnode = listnode->next;

        if (listnode == nullptr || listnode->next == nullptr) return listnode;
        for (ListNode* ptr = listnode; ptr->next != nullptr; ptr = ptr->next)
        {
            while (ptr->next != nullptr && ptr->next->val == val) ptr->next = ptr->next->next;
            if (ptr->next == nullptr) break;
        }

        return listnode;
    }
};

int main()
{
    ListNode* test_sample = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(6, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    int val = 6;

    Solution* solution = new Solution();
    ListNode* result = solution->removeElements(test_sample, val);

    while (result != nullptr)
    {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}