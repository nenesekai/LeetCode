#include <iostream>
#include <vector>
#include "listnode.h"

using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *node = ListNode::vectorToListNode(vec);
    ListNode::printListNode(node);
    ListNode::deleteListNode(node);
    return 0;
}