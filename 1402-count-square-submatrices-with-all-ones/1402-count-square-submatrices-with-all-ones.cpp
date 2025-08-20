class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, int newi, int newj) {
        int sum = 0;
        for (int k = i; k <= newi; k++) {
            for (int l = j; l <= newj; l++) {
                sum += matrix[k][l];
            }
        }
        return sum;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; i + k < n && j + k < m; k++) {
                    int newi = i + k;
                    int newj = j + k;
                    int sum = solve(matrix, i, j, newi, newj);
                    int temp = (newi - i + 1) * (newj - j + 1);
                    if (sum == temp) total++;
                    else break;
                }
            }
        }
        return total;
    }
};