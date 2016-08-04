/* 79. Word Search
 *Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false. 
 *
 * */

class Solution {
public:
    int H,W;
    bool valid(int i, int j)
    {
        if (i >= 0 && i < H && j >= 0 && j < W)
            return true;
        else
            return false;
    }
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>&visited, string& word, int start, int x1, int x2)
    {
        bool r = false;
        if(start == word.size())
            return true;
        if (!valid(x1,x2) || board[x1][x2] != word[start])
            return false;
            
        if(!visited[x1][x2] && start == word.size()-1)
            return true;
    
        visited[x1][x2] = true;
        if (valid(x1+1, x2) && !visited[x1+1][x2] && dfs(board, visited, word, start+1, x1+1,x2))
            r = true;
        else if (valid(x1-1,x2) && !visited[x1-1][x2] && dfs(board,visited, word,start+1, x1-1,x2))
            r = true;
        else if (valid(x1,x2-1) && !visited[x1][x2-1] && dfs(board,visited, word, start+1, x1, x2-1))
            r = true;
        else if (valid(x1, x2+1) && !visited[x1][x2+1] && dfs(board, visited, word, start+1, x1, x2+1))
            r = true;
        visited[x1][x2] = false;
        return r;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        H = board.size();
        W = board[0].size();
        vector<vector<bool>> visited(H, vector<bool>(W,false));
        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++)
            {
                if (dfs(board, visited, word, 0, i, j))
                    return true;
            }
        return  false;
    }
};
