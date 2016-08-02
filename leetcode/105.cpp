/*
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
 *
 * */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int p_s, int p_e, int i_s, int i_e)
    {
        if (p_e < p_s)
            return NULL;
        if (p_e == p_s)
        {
            return new TreeNode(preorder[p_s]);
        }
        int t = preorder[p_s];
        // find t in inorder
        int idx = -1;
        for(int i = i_s; i <= i_e; i++)
        {
            if (inorder[i] == t)
            {
                idx = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(t);
        int len = idx - i_s;
        root->left = buildTree(preorder, inorder, p_s+1, p_s + len, i_s, i_s + len-1);
        root->right = buildTree(preorder, inorder, p_s+len+1, p_e, i_s+len+1, i_e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
        
    }
};
