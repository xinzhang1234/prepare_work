/*
 * 95. Unique Binary Search Trees II
 * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 *
    1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3*
 * */

class Solution {
public:
    vector<TreeNode*> dfs(int s, int e)
    {
        vector<TreeNode*> result;
        if (s > e)
            return result;
        if (s == e)
        {
            result.push_back(new TreeNode(s));
            return result;
        }
        for (int i = s; i <= e; i++)
        {
            vector<TreeNode*> L = dfs(s,i-1);
            vector<TreeNode*> R = dfs(i+1,e);
            if (L.size() < 1)
            {
                if (R.size() > 0)
                {
                    for(int j = 0; j < R.size(); j++)
                    {
                        TreeNode* tmp = new TreeNode(i);
                        tmp->right = R[j];
                        result.push_back(tmp);
                    }
                }
            }
            else if (R.size() < 1)
            {
                if (L.size() > 0)
                {
                    for (int j = 0; j < L.size(); j++)
                    {
                        TreeNode* tmp = new TreeNode(i);
                        tmp->left = L[j];
                        result.push_back(tmp);
                    }
                }
            }
            else
            {
            for (int j = 0; j < L.size(); j++)
                for(int k = 0; k < R.size(); k++)
                {
                    TreeNode* tmp = new TreeNode(i);
                    tmp->left = L[j];
                    tmp->right = R[k];
                    result.push_back(tmp);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1,n);
    }
};
