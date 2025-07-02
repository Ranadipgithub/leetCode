class Solution {
public:
    void solve(int row, int n, vector<string> &board, vector<vector<string>> &res,
               vector<int> &column, vector<int> &diag1, vector<int> &diag2) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (column[col] == 0 && diag1[row - col + n - 1] == 0 && diag2[row + col] == 0) {
                column[col] = 1;
                diag1[row - col + n - 1] = 1;
                diag2[row + col] = 1;
                board[row][col] = 'Q';

                solve(row + 1, n, board, res, column, diag1, diag2);

                column[col] = 0;
                diag1[row - col + n - 1] = 0;
                diag2[row + col] = 0;
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> column(n, 0);
        vector<int> diag1(2 * n - 1, 0);
        vector<int> diag2(2 * n - 1, 0);
        solve(0, n, board, res, column, diag1, diag2);
        return res;
    }
};
