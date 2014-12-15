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
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 || head == NULL)
            return head;
        ListNode *start = head, *end = start;
        for (int i = 0; i < k; ++i)
		{
			if (end->next == NULL)
				end = head;
			else
				end = end->next;
		}
        while (end->next)
        {
            start = start->next;
            end = end->next;
        }
        end->next = head;
        ListNode *result = start->next;
        start->next = NULL;
        return result;
    }
};