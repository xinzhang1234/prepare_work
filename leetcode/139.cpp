/*139. Word Break
 * Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
 */

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> V(s.size() + 1, false);
        V[0] = true;
        int i,j;
        for(i = 1; i < V.size(); i++)
        {
            for (j = i-1; j >=0; j--)
            {
                string t = s.substr(j,i-j);
                if (V[j] && (wordDict.find(t) != wordDict.end()))
                {
                    V[i] = true;
                    break;
                }
            }
        }
        return V[V.size()-1];
    }
};
