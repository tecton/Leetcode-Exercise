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
    bool validBST(TreeNode *root, int minVal, int maxVal)
    {
        if (root == NULL)
            return true;
        if (!(root->val > minVal && root->val < maxVal))
            return false;
        return validBST(root->left, minVal, root->val) && validBST(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode *root) {
        return validBST(root, INT_MIN, INT_MAX);
    }
};