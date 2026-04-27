class Solution {
public:
    const int mod = 1e9+7;
    int dp[10001][6][11][11];
    long long solve(int i, int j, string &s, char x, char y){
        if(j >= 5) return 1;
        if(i >= s.size()) return 0;

        int xi = (x == '$' ? 10 : x - '0');
        int yi = (y == '$' ? 10 : y - '0');
        if(dp[i][j][xi][yi] != -1) return dp[i][j][xi][yi];
        long long ways = 0;

        if(j == 0){
            ways = (ways + solve(i+1, j+1, s, s[i], y)) % mod;
            ways = (ways + solve(i+1, j, s, x, y)) % mod;
        } else if(j == 1){
            ways = (ways + solve(i+1, j+1, s, x, s[i])) % mod;
            ways = (ways + solve(i+1, j, s, x, y)) % mod;
        } else if(j == 2){
            ways = (ways + solve(i+1, j+1, s, x, y)) % mod;
            ways = (ways + solve(i+1, j, s, x, y)) % mod;
        } else if (j == 3){
            if(s[i] == y){
                ways = (ways + solve(i+1, j+1, s, x, y)) % mod;
            }
            ways = (ways + solve(i+1, j, s, x, y)) % mod;
        } else if(j == 4){
            if(s[i] == x){
                ways = (ways + solve(i+1, j+1, s, x, y)) % mod;
            }
            ways = (ways + solve(i+1, j, s, x, y)) % mod;
        }

        return dp[i][j][xi][yi] = (ways % mod + mod) % mod;
    }

    int countPalindromes(string s) {
        memset(dp, -1, sizeof(dp));
        return (solve(0, 0, s, '$', '$') % mod + mod) % mod;
    }
};