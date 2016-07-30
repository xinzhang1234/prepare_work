/*
 * 98. Validate Binary Search Tree
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
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
    bool dfs(TreeNode* root, double minv, double maxv)
    {
        if (!root)
            return true;
            
        if (root->val > minv && root->val < maxv)
        {
            if (dfs(root->left, minv, min(maxv, double(root->val))) && dfs(root->right, max(minv, double(root->val)), maxv))
                return true;
            else
                return false;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, double(INT_MIN)-1, double(INT_MAX)+1);
    }
};
