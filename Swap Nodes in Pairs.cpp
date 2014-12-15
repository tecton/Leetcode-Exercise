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
    ListNode *swapPairs(ListNode *head) {
        ListNode *p1 = head, *p2, *pre = new ListNode(-1), *newHead = p1;
        if (p1 && p1->next)
            newHead = p1->next;
        while (p1 && p1->next)
        {
            p2 = p1->next;
            p1->next = p2->next;
            p2->next = p1;
            pre->next = p2;
            pre = p1;
            p1 = p1->next;
        }
        return newHead;
    }
};