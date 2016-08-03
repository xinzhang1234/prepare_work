/*216. Combination Sum III
 * Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 * Example 1:
 *
 * Input: k = 3, n = 7
 *
 * Output:
 *
 * [[1,2,4]]
 * */

/*notice: all the element in returned array must in [1,9]*/
class Solution {
public:
map<int, bool> visited;
vector<vector<int>> C(int k, int n, int start)
{
    vector<vector<int>> V;
    if (k <= 0)
        return V;
    if (k == 1)
    {
        if (n > start && n < 10 && !visited[n])
        {
            V.push_back(vector<int>(1,n));
            return V;
        }
    }
    
    for(int i = start+1; i <= n && i < 10; i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        vector<vector<int>> tmp = C(k-1, n-i, i);
        for(int j = 0; j < tmp.size(); j++)
        {
            tmp[j].push_back(i);
            V.push_back(tmp[j]);
        }
        visited[i] = false;
    }
    return V;
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> V = C(k,n,0);
    for(int i = 0; i < V.size(); i++)
    {
        sort(V[i].begin(), V[i].end());
    }
    return V;
}
};


