#include "listnode.h"

#include <iostream>

ListNode::ListNode()
    : val(0), next(nullptr)
{}

ListNode::ListNode(int val)
    : val(val), next(nullptr)
{}

ListNode::ListNode(int val, ListNode *next)
    : val(val), next(next)
{}

ListNode *ListNode::vectorToListNode(std::vector<int> &vec)
{
    ListNode *head = nullptr;
    ListNode **curr = &head;

    for (int val : vec)
    {
        *curr = new ListNode(val);
        curr = &((*curr)->next);
    }

    return head;
}

void ListNode::printListNode(ListNode *node)
{
    if (node)
    {
        std::cout << node->val << " ";
        printListNode(node->next);
    }
    else
    {
        std::cout << std::endl;
        return;
    }
}

void ListNode::deleteListNode(ListNode *node)
{
    if (!node) return;
    if (node->next) deleteListNode(node->next);
    delete node;
}