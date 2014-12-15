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
    bool isSymmetricNodes(TreeNode *node1, TreeNode *node2)
    {
        if (node1 != NULL && node2 != NULL)
            return node1->val == node2->val
            && isSymmetricNodes(node1->left, node2->right)
            && isSymmetricNodes(node1->right, node2->left);
        if (node1 == NULL && node2 == NULL)
            return true;
        return false;
    }
    bool isSymmetric(TreeNode *root) {
        return isSymmetricNodes(root, root);
    }
};