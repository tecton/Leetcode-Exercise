/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *constructTree(ListNode *head, int length)
    {
        if (length <= 0)
            return NULL;
        int middle = length / 2;
        ListNode *cur = head;
        for (int i = 0; i < middle; ++i)
            cur = cur->next;
        TreeNode *node = new TreeNode(cur->val);
        node->left = constructTree(head, middle);
        node->right = constructTree(cur->next, length - middle - 1);
        return node;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        int length = 0;
        ListNode *cur = head;
        while (cur)
        {
            length++;
            cur = cur->next;
        }
        return constructTree(head, length);
    }
};