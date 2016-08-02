/*
 * 124. Binary Tree Maximum Path Sum
 * Given a binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.
 *
 * For example:
 * Given the below binary tree,
 *
 *   1
      / \
     2   3
Return 6. 
 * */

class Solution {
public:
    int max_value = INT_MIN;
    int dfs(TreeNode* root)
    {
        /*return the max value path */ 
        if (!root)
            return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        int sum = root->val;
        if (L > 0)
            sum += L;
        if (R > 0)
            sum += R;
        max_value = max(sum, max_value);
        
        return (max(L,R) > 0 ? max(L,R) + root->val : root->val);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_value;
    }
};
