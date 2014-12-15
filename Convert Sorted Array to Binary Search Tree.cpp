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
    TreeNode *constructTree(vector<int> &num, int start, int end)
    {
        if (start > end)
            return NULL;
        int middle = (start + end) / 2;
        TreeNode *node = new TreeNode(num[middle]);
        //if (middle > start)
            node->left = constructTree(num, start, middle - 1);
        //if (middle < end)
            node->right = constructTree(num, middle + 1, end);
        return node;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return constructTree(num, 0, num.size() - 1);
    }
};