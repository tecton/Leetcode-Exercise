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
    TreeNode *buildTree(vector<int> &inorder, int iStart, int iEnd, vector<int> &postorder, int pStart, int pEnd)
    {
        if (iEnd < iStart)
            return NULL;
        TreeNode *node = new TreeNode(postorder[pEnd]);
        int iNode = iStart;
        while (iNode != iEnd)
        {
            if (postorder[pEnd] == inorder[iNode])
                break;
			iNode++;
        }
        node->right = buildTree(inorder, iNode + 1, iEnd, postorder, pEnd - (iEnd - iNode), pEnd - 1);
        node->left = buildTree(inorder, iStart, iNode - 1, postorder, pStart, pEnd - (iEnd - iNode) - 1);
		return node;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};