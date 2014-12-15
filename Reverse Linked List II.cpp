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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n)
            return head;
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        int count = 0;
        ListNode *iter = dummyHead, *riter = NULL, *reverseStart, *reverseEnd;
        while (count < n)
        {
            if (count + 1 >= m && count + 1 <= n)
            {
                if (count + 1 == m)
                {
                    reverseStart = iter;
                    reverseEnd = iter->next;
                }
                ListNode *temp = riter;
                riter = iter->next;
                iter->next = iter->next->next;
                riter->next = temp;
                
                if (count + 1 == n)
                {
                    reverseEnd->next = iter->next;
                    reverseStart->next = riter;
                }
            }
            else
            {
				iter = iter->next;
			}
            count++;
        }
        return dummyHead->next;
    }
};