class Solution {
public:
    bool check(int num, vector<vector<char>>& board, int i, int j){
        char c = '0' + num;
        for(int col = 0;col<9;col++){
            if(board[i][col] == c) return 0;
        }
        for(int row = 0;row<9;row++){
            if(board[row][j] == c) return 0;
        }
        int row = i/3*3, col = j/3*3;
        for(int a = 0;a<3;a++){
            for(int b = 0;b<3;b++){
                if((a+row != i) && (b + col != j) && board[a+row][b+col] == c) return 0;
            }
        }
        return 1;
    }
    bool solve(int i, int j, vector<vector<char>>& board){
        if(i == 9) return true;
        if(j==9) return solve(i+1, 0, board);
        if(board[i][j] != '.') return solve(i, j+1, board);

        for(int num = 1;num<10;num++){
            if(check(num, board, i, j)){
                board[i][j] = '0' + num;
                if(solve(i, j+1, board)) return 1;
                board[i][j] = '.';
            }
        }

        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, board);
    }
};