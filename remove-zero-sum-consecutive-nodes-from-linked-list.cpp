#include <iostream>
#include <unordered_map>
#include "listnode.h"

using namespace std;

class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        unordered_map<int, ListNode *> presum;

        int sum = 0;
        for (ListNode *curr = dummy; curr; curr = curr->next)
        {
            sum += curr->val;
            presum[sum] = curr;
        }

        sum = 0;
        for (ListNode *curr = dummy; curr; curr = curr->next)
        {
            sum += curr->val;
            curr->next = presum.find(sum)->second->next;
        }

        // 0 1 2 3 -3 -2
        // 0 1 3 6 3 1

        return dummy->next;
    }
};

int main()
{
    vector<int> vec = {1, 2, 3, -3, -2};
    ListNode *head = ListNode::vectorToListNode(vec);
    Solution *obj = new Solution();
    ListNode *result = obj->removeZeroSumSublists(head);
    ListNode::printListNode(result);
    ListNode::deleteListNode(head);
    ListNode::deleteListNode(result);
    delete obj;
    return 0;
}