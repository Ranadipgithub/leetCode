class Solution {
public:
    int dp[1002][1002];
    int solve(int curr, int last, vector<pair<int, int>> &players){
        if(curr >= players.size()) return 0;
        if(dp[curr+1][last+1] != -1) return dp[curr+1][last+1];
        int take = 0, skip = 0;
        if(last == -1) {
            take = players[curr].second + solve(curr+1, curr, players);
            skip = solve(curr+1, last, players);
        } else {
            if(players[curr].first > players[last].first && players[curr].second < players[last].second){
                skip = solve(curr+1, last, players);
            } else {
                take = players[curr].second + solve(curr+1, curr, players);
                skip = solve(curr+1, last, players);
            }
        }
        return dp[curr+1][last+1] = max(take, skip);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        memset(dp, -1, sizeof(dp));
        vector<pair<int, int>> players(n);
        for(int i = 0;i<n;i++){
            players[i] = {ages[i], scores[i]};
        }
        sort(players.begin(), players.end());
        return solve(0, -1, players);
    }
};