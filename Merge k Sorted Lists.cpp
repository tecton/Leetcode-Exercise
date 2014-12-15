/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *mergedRoot = new ListNode(0);
        ListNode *p = mergedRoot;
        
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1 != NULL)
            p->next = l1;
        else if (l2 != NULL)
            p->next = l2;
        return mergedRoot->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        while (lists.size() > 1)
        {
            ListNode *mergedList = mergeTwoLists(lists[0], lists[1]);
            lists.push_back(mergedList);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        if (lists.size() == 1)
            return lists[0];
        else
            return NULL;
    }
};