/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
    		return NULL;
    	RandomListNode *dummyHead = new RandomListNode(0);
    	RandomListNode *p1 = dummyHead, *p2 = head;
    	unordered_map<RandomListNode*, RandomListNode*> mapping;
    	while (p2)
    	{
    		if (mapping.find(p2) != mapping.end())
    		{
    			p1->next = mapping.find(p2)->second;
    		}
    		else
    		{
    			p1->next = new RandomListNode(p2->label);
    			mapping[p2] = p1->next;
    		}
    		if (p2->random)
    		{
    			if (mapping.find(p2->random) != mapping.end())
    			{
    				p1->next->random = mapping.find(p2->random)->second;
    			}
    			else
    			{
    				p1->next->random = new RandomListNode(p2->random->label);
    				mapping[p2->random] = p1->next->random;
    			}
    		}
    		p2 = p2->next;
    		p1 = p1->next;
    	}
    	return dummyHead->next;
    }
};