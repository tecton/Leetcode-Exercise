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
    int maxDepth(TreeNode *root) {
        int leftDepth = 0, rightDepth = 0;
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        if (root->left != NULL)
            leftDepth = 1 + maxDepth(root->left);
        if (root->right != NULL)
            rightDepth = 1 + maxDepth(root->right);
        return leftDepth > rightDepth ? leftDepth: rightDepth;
    }
};