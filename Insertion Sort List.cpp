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
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *toInsert = dummy, *pos = dummy, *temp;
        while (toInsert->next)
        {
            pos = dummy;
            while (pos != toInsert)
            {
                if (pos->val <= toInsert->next->val && pos->next->val > toInsert->next->val)
                {
                    temp = toInsert->next;
                    toInsert->next = temp->next;
                    temp->next = pos->next;
                    pos->next = temp;
                    break;
                }
                pos = pos->next;
            }
            if (pos == toInsert)
                toInsert = toInsert->next;
        }
        return dummy->next;
    }
};