class Solution {
public:
    bool notInDiag(int row, int col, vector<string> &board, int n){
        int i = row, j = col;
        while(i>-1 && j > -1){
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        i = row, j = col;
        while(i>-1 && j < n){
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void solve(int row, int n, vector<string> &board, vector<vector<string>> &res, vector<int> &column){
        if(row == n){
            res.push_back(board);
            return;
        }
        for(int i = 0;i<n;i++){
            if(column[i] == 0 && notInDiag(row, i, board, n)){
                column[i] = 1;
                board[row][i] = 'Q';
                solve(row+1, n, board, res, column);
                column[i] = 0;
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> column(n, 0);
        solve(0, n, board, res, column);
        return res;
    }
};