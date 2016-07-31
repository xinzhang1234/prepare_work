/*
 * 310. Minimum Height Trees
 * For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.
 *
 * Format
 * The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
 *
 * You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 * Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 *
 *   0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4] 
 * */

/*main idea:
一种是先计算每个点的degree，然后将degree为1的点放入list或者queue中进行计算，把这些点从neighbours中去除，然后计算接下来degree = 1的点。最后剩下1 - 2个点就是新的root 
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> R;
        if (n == 1)
        {
            R.push_back(0);
            return R;
        }
        map<int, set<int>> M;
        queue<int> Q;
        set<int> visited;
        for(int i = 0; i < edges.size(); i++)
        {
            M[edges[i].first].insert(edges[i].second);
            M[edges[i].second].insert(edges[i].first);
        }
        for(auto it = M.begin(); it != M.end(); it++)
        {
            if (it->second.size() == 1)
            {
                Q.push(it->first);
                //cout << it->first << endl;
            }
        }
        while(n > 2)
        {
            n -= Q.size();
            while(!Q.empty())
            {
                int tmp = Q.front();
                visited.insert(tmp);
                Q.pop();
                set<int> S = M[tmp];
                for (auto iit = S.begin(); iit != S.end(); iit++)
                {
                    M[*iit].erase(tmp);
                }
                M[tmp].clear();
            }
            for(auto it = M.begin(); it != M.end(); it++)
            {
                if (it->second.size() == 1)
                    Q.push(it->first);
            }
        }
       
        for (auto it = M.begin(); it != M.end(); it++)
        {
            if (visited.find(it->first) == visited.end())
                R.push_back(it->first);
        }
        return R;
    }
};
