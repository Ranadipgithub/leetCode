class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        int n = board.size();
        int m = board[0].size();
        if(i<0 || i>=n || j<0 || j>=m || board[i][j] != 'X') return;
        board[i][j] = '0';
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == 'X'){
                    dfs(board, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};