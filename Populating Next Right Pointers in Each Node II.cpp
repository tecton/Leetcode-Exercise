/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        TreeLinkNode *cur = root, *prev = NULL, *levelHead = NULL;
        while (cur != NULL)
        {
            while (cur != NULL)
            {
                if (cur->left)
                {
                    if (prev)
                        prev->next = cur->left;
                    else
                        levelHead = cur->left;
                    prev = cur->left;
                }
                if (cur->right)
                {
                    if (prev)
                        prev->next = cur->right;
                    else
                        levelHead = cur->right;
                    prev = cur->right;
                }
                cur = cur->next;
            }
            cur = levelHead;
            prev = NULL;
            levelHead = NULL;
        }
    }
};