class Solution {
public:
    bool check(int num, vector<vector<char>>& board, int i, int j){
        char c = '0' + num;
        for(int col = 0;col<9;col++){
            if(board[i][col] == c && (col != j)) return 0;
        }
        for(int row = 0;row<9;row++){
            if(board[row][j] == c && (row != i)) return 0;
        }
        int row = i/3*3, col = j/3*3;
        for(int a = 0;a<3;a++){
            for(int b = 0;b<3;b++){
                if((a+row != i) && (b + col != j) && board[a+row][b+col] == c) return 0;
            }
        }
        return 1;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    if(!check(num, board, i, j)) return false;
                }
            }
        }
        return true;
    }
};