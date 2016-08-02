/*
 * 173. Binary Search Tree Iterator
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree
 * */

class BSTIterator {
public:
    stack<TreeNode*> S;
    int nextmin;
    BSTIterator(TreeNode *root) {
        TreeNode* p = root;
        while(p)
        {
            S.push(p);
            p = p->left;
        }
    }

    /** @return whether we have a next smallest number */
	/* if it has left child, push all the left child to stack
		then go to right child, and push right child's left to stack
	*/
    bool hasNext() {
        if(!S.empty())
        {
            TreeNode* t = S.top();
            S.pop();
            nextmin = t->val;
            t = t->right;
            if (t)
            {
                S.push(t);
                t = t->left;
                while(t)
                {
                    S.push(t);
                    t = t->left;
                }
            }
            return true;
        }
        else
            return false;
    }

    /** @return the next smallest number */
    int next() {
        return nextmin;
    }
};
