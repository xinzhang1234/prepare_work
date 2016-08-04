/*230. Kth Smallest Element in a BST
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 *
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * */

/*inorder traverse the BST tree, return kth number*/


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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> S;
        TreeNode* p;
        p = root;
        int cnt = 0;
        while(p || !S.empty())
        {
            if(p)
            {
                S.push(p);
                p = p->left;
            }
            else
            {
                p = S.top();
                S.pop();
                //cout << p->val << endl;
                cnt++;
                if (cnt == k)
                    return p->val;
                p = p->right;
            }
        }
        return -1;
    }
};
