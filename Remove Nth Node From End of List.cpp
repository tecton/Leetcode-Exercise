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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *p = dummyHead, *fast = p;
        while (n--)
            fast = fast->next;
        while (fast && fast->next)
        {
            p = p->next;
            fast = fast->next;
        }
        p->next = p->next->next;
        return dummyHead->next;
    }
};