#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{

private:

    ListNode* head;

public:

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        head = new ListNode(INT_MIN);

        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];

        for (ListNode* &list : lists)
        {
            if (!list) continue;

            ListNode* listCurr = list;
            ListNode* nodeCurr = head;

            while (listCurr)
            {
                while (nodeCurr->next && nodeCurr->next->val < listCurr->val)
                {
                    nodeCurr = nodeCurr->next;
                }

                ListNode* newNode = new ListNode(listCurr->val, nodeCurr->next);

                nodeCurr->next = newNode;

                listCurr = listCurr->next;
            }
        }
        
        return head->next;
    }

};

int main()
{
    return 0;
}