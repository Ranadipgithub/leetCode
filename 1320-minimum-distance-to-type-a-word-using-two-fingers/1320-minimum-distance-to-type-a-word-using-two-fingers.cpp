class Solution {
public:
    int dp[301][27][27];
    int solve(int idx, int left, int right, string &word){
        if(idx >= word.size()) return 0;
        if(dp[idx][left + 1][right + 1] != -1) return dp[idx][left + 1][right + 1];
        int pos = word[idx]-'A';
        int i = pos/6, j = pos%6;
        // we have the option to either type the letter using left hand or right hand
        int op1;
        if(left == -1) op1 = solve(idx+1, pos, right, word);
        else {
            int li = left/6, lj = left % 6;
            int dist = abs(li-i) + abs(lj-j);
            op1 = dist + solve(idx+1, pos, right, word);
        }
        int op2;
        if(right == -1) op2 = solve(idx+1, left, pos, word);
        else {
            int ri = right/6, rj = right%6;
            int dist = abs(ri-i) + abs(rj - j);
            op2 = dist + solve(idx+1, left, pos, word);
        }
        return dp[idx][left + 1][right + 1] = min(op1, op2);
    }
    int minimumDistance(string word) {
        int n = word.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, -1, word);
    }
};