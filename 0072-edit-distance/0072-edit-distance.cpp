class Solution {
public:
    int t[501][501];
    int solve(string &word1, string &word2, int i, int j){
        if(i == word1.size()) return word2.size() - j;
        else if(j == word2.size()) return word1.size() - i;
        if(t[i][j] != -1) return t[i][j];
        if(word1[i] == word2[j]) return t[i][j] = solve(word1, word2, i+1, j+1);
        else {
            int insert = 1 + solve(word1, word2, i, j+1);
            int deleteOp = 1+  solve(word1, word2, i+1, j);
            int replace = 1 + solve(word1, word2, i+1, j+1);
            return t[i][j] = min({insert, deleteOp, replace});
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        memset(t, -1, sizeof(t));

        return solve(word1, word2, 0, 0);
    }
};