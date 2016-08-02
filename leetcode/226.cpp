/*226. Invert Binary Tree
 * Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1 
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root || (!root->left && !root->right)) 
            return root;
        TreeNode* L = invertTree(root->left);
        TreeNode* R = invertTree(root->right);
        root->left = R;
        root->right = L;
        return root;
    }
};
