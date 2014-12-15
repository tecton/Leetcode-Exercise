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
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *smaller = dummyHead, *larger = new ListNode(0);
        ListNode *result = smaller, *largerHead = larger;
        while (smaller && smaller->next)
        {
            if (smaller->next->val >= x)
            {
                larger->next = smaller->next;
                larger = larger->next;
                smaller->next = smaller->next->next;
				larger->next = NULL;
            }
            else
                smaller = smaller->next;
        }
        smaller->next = largerHead->next;
        return result->next;
    }
};