/*199. Binary Tree Right Side View
 *Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
 * */

/*level traverse*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> R;
        queue<TreeNode*> Q;
        TreeNode* last;
        if (!root)
            return R;
        TreeNode* tmp = new TreeNode(-1);
        Q.push(root);
        Q.push(tmp);
        while(!Q.empty())
        {
            TreeNode* cur = Q.front();
            Q.pop();
            if (cur == tmp)
            {
                R.push_back(last->val);
                if (!Q.empty())
                    Q.push(tmp);
            }
            else
            {
                last = cur;
                if(cur->left)
                    Q.push(cur->left);
                if(cur->right)
                    Q.push(cur->right);
            }
        }
        return R;
    }
};
