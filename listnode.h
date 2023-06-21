#ifndef LISTNODE_H
#define LISTNODE_H

#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode();
    ListNode(int);
    ListNode(int, ListNode *);
    
    static ListNode *vectorToListNode(std::vector<int> &);
    static void printListNode(ListNode *);
    static void deleteListNode(ListNode *);
};

#endif