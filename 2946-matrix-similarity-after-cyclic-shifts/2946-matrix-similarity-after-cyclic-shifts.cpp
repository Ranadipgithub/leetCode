class Solution {
public:
  bool areSimilar(vector<vector<int>> &mat, int k) {
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; ++i) {
      int shift = k % n;
      for (int j = 0; j < n; ++j) {
        int orj;
        if (i % 2 == 0) {
          orj = (j + shift) % n;
        } else {
          orj = (j - shift + n) % n;
        }
        if (mat[i][j] != mat[i][orj]) {
          return false;
        }
      }
    }
    return true;
  }
};