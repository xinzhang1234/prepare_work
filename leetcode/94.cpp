/*94. Binary Tree Inorder Traversal
 *
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].
* */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> V;
        stack<TreeNode*> S;
        TreeNode* p;
        if (!root)
            return V;
        p = root;
        while(p || !S.empty())
        {
            if (p)
            {
                S.push(p);
                p = p->left;
            }
            else
            {
                p = S.top();
                S.pop();
                V.push_back(p->val);
                p = p->right;
            }
        }
        return V;
    }
};
