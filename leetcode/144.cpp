/* 144. Binary Tree Preorder Traversal
 * Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3]. 
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> result;
        if (root)
            S.push(root);
        else
            return result;
        
        TreeNode* p = root;
        while(!S.empty())
        {
            p = S.top();
            S.pop();
            result.push_back(p->val);
            if (p->right)
                S.push(p->right);
            if (p->left)
                S.push(p->left);
        }
        return result;
    }
};
