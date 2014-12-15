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
    TreeNode *buildTree(vector<int> &inorder, int iStart, int iEnd, vector<int> &preorder, int pStart, int pEnd)
    {
        if (iEnd < iStart)
            return NULL;
        TreeNode *node = new TreeNode(preorder[pStart]);
        int iNode = iStart;
        while (iNode != iEnd)
        {
            if (preorder[pStart] == inorder[iNode])
                break;
			iNode++;
        }
        node->left = buildTree(inorder, iStart, iNode - 1, preorder, pStart + 1, pStart + (iNode - iStart));
        node->right = buildTree(inorder, iNode + 1, iEnd, preorder, pStart + (iNode - iStart) + 1, pEnd);
		return node;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1);
    }
};