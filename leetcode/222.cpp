/*
 * 222. Count Complete Tree Nodes
 * Given a complete binary tree, count the number of nodes.
 *
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
 *
 * main idea:
 * 如果从某节点一直向左的高度 = 一直向右的高度, 那么以该节点为root的子树一定是complete binary tree. 而 complete binary tree的节点数,可以用公式算出 2^h - 1. 如果高度不相等, 则递归调用 return countNode(left) + countNode(right) + 1.  复杂度为O(h^2) 
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
    bool equal(TreeNode* T, int *h)
    {
        if (!T)
            return true;
        int L,R;
        L = 0;
        R = 0;
        TreeNode* p = T;
        while(p)
        {
            L++;
            p = p->left;
        }
        p = T;
        while(p)
        {
            R++;
            p = p->right;
        }
        *h = L;
        return L == R;
    }
    int countNodes(TreeNode* root) {
        int L, R;
        L = 0;
        R = 0;
        if (equal(root, &L))
            return (1 << L) - 1;
        else
            return (1 + countNodes(root->left) + countNodes(root->right));
    }
};
