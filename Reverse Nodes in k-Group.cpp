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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummyHead = new ListNode(0);
    	dummyHead->next = head;
    	ListNode *reverseEnd, *p1 = dummyHead, *p2, *r, *temp;
    	int totalNodes = 0;
    	while (p1->next)
    	{
    		p1 = p1->next;
    		totalNodes++;
    	}
    	if (totalNodes < k)
    		return head;
    	p1 = dummyHead;
    	for (int i = 0; i < totalNodes / k; ++i)
    	{
    		reverseEnd = p1->next;
    		p2 = p1;
    		r = NULL;
    		for (int j = 0; j < k; ++j)
    		{
    			temp = r;
    			r = p2->next;
    			p2->next = p2->next->next;
    			r->next = temp;
    		}
    		reverseEnd->next = p1->next;
    		p1->next = r;
    		p1 = reverseEnd;
    	}
    	return dummyHead->next;
    }
};