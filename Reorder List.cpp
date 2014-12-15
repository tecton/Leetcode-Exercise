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
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next)
            return;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy, *fast = dummy;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l1 = head, *reversed = NULL;
        while (slow->next)
        {
            ListNode *temp = slow->next;
            slow->next = slow->next->next;
            temp->next = reversed;
            reversed = temp;
        }
		int i = 0;
		slow = dummy;
		while (l1 && reversed)
		{
			slow->next = l1;
			l1 = l1->next;
			slow->next->next = reversed;
			reversed = reversed->next;
			slow = slow->next->next;
		}
		head = dummy->next;
    }
};