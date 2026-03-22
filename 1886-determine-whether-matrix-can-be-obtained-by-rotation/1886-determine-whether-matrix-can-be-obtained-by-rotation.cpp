class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i = 0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
    bool check(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool fg = check(mat, target);
        if(fg) return true;
        for(int i = 0;i<4;i++){
            rotate(mat);
            if(check(mat, target)) return true;
        }
        return false;
    }
};