class Solution {
public:
    vector<int> leftShift(vector<int> arr, int k){
        int n = arr.size();
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin()+n-k);
        reverse(arr.begin()+n-k, arr.end());
        return arr;
    }
    vector<int> rightShift(vector<int> arr, int k){
        int n = arr.size();
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());
        return arr;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> res = mat;

        k = k%m;
        for(int i= 0;i<n;i++){
            if(i%2 == 0){
                res[i] = leftShift(mat[i], k);
            } else{
                res[i] = rightShift(mat[i], k);
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] != res[i][j]) return false;
            }
        }
        return true;
    }
};