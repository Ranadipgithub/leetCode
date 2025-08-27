class Solution {
public:
    vector<int> intersectionUnique(vector<int>& a, vector<int>& b) {
        unordered_set<int> s(a.begin(), a.end());
        vector<int> res;
        for (int x : b) {
            if (s.find(x) != s.end()) {
                res.push_back(x);
                s.erase(x);
            }
        }
        return res;
    }

    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> mini(n);
        for(int i = 0;i<n;i++){
            mini[i] = *min_element(matrix[i].begin(), matrix[i].end());
        }
        vector<int> maxi(m);
        for(int j = 0;j<m;j++){
            int maxii = matrix[0][j];
            for(int i = 0;i<n;i++){
                maxii = max(maxii, matrix[i][j]);
            }
            maxi[j] = maxii;
        }
        return intersectionUnique(maxi, mini);
    }
};