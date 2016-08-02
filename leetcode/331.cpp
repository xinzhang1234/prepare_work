/*
331. Verify Preorder Serialization of a Binary Tree
 One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false*
 * */

/* main idea:
	push the string into stack. If it is 9,#,#, we will pop out 9,#,# and push #, 
	if the final stack is # or empty and the string is all visited, return true
*/

class Solution {
public:
queue<string> split(string s)
{
    queue<string> V;
    int start = -1;
    int i;
    for(i = 0; i < s.size(); i++)
    {
        if (s[i] == ',')
        {
            V.push(s.substr(start+1, i-start-1));
            start = i;
        }
    }
    V.push(s.substr(start+1, i - start - 1));
    return V;
}

bool isValidSerialization(string preorder) {
    // seperate string
    queue<string> V = split(preorder);
    stack<string> S;
    while(!V.empty())
    {
        string tmp = V.front();
        V.pop();
        while (tmp == "#" && !S.empty() && S.top() == "#")
        {
            S.pop();
            if (S.empty())
                return false;
            S.pop();
            if (S.empty())
            {
                if (V.empty())
                    return true;
                else
                    return false;
            }
        }
        S.push(tmp);
    }
    if (S.top() == "#")
    {
        S.pop();
        if (S.empty())
            return true;
    }
    return S.empty();
}
};
