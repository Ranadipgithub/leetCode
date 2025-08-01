class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        unordered_map<int, vector<int>> diagonals;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                diagonals[i - j].push_back(mat[i][j]);
            }
        }

        for (auto& pair : diagonals) {
            sort(pair.second.begin(), pair.second.end());
        }

        unordered_map<int, int> p; 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mat[i][j] = diagonals[i - j][p[i - j]];
                p[i - j]++; 
            }
        }

        return mat;
    }
};