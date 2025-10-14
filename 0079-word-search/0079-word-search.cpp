class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool dfs(int i, int j, vector<vector<char>>& board, string word, string temp, int idx, vector<vector<int>>&visited){
        int n = board.size(), m = board[0].size();
        if(idx >= word.size()){
            return true;
        }
        for(auto &dir: directions){
            int newi = i + dir[0];
            int newj = j + dir[1];
            if(newi >= 0 && newi < n && newj >= 0 && newj < m && !visited[newi][newj] && board[newi][newj] == word[idx]){
                visited[newi][newj] = 1;
                if(dfs(newi, newj, board, word, temp, idx+1, visited)) return true;
                visited[newi][newj] = 0;
            } 
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == word[0]){
                    vector<vector<int>> visited(n, vector<int>(m, 0));
                    visited[i][j] = 1;
                    if(dfs(i, j, board, word, "", 1, visited)) return true;
                }
            }
        }
        return false;
    }
};