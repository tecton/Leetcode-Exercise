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
    ListNode *deleteDuplicates(ListNode *head) {
    	if (!head)
    		return NULL;
    	ListNode *dummyHead = new ListNode(0), *iter = dummyHead, *end, *start;
    	dummyHead->next = head;
    	while (iter && iter->next)
    	{
    		start = iter->next;
    		end = start->next;
    		while (end && end->val == start->val)
    			end = end->next;
    		if (start->next != end)
    			iter->next = end;
    		else
    		{
    			iter->next = start;
    			iter = iter->next;
    		}
    	}
    	return dummyHead->next;
    }
};