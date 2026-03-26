class Solution {
public:
    bool isValidRemoval(int r, int c, int r1, int r2, int c1, int c2) {
        if (r < r1 || r > r2 || c < c1 || c > c2) return false;
        if (r1 == r2 && c1 == c2) return false;
        if (r1 == r2) return c == c1 || c == c2;
        if (c1 == c2) return r == r1 || r == r2;
        return true; 
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long total = 0;
        unordered_map<long long, vector<pair<int, int>>> mpp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mpp[grid[i][j]].push_back({i, j});
                total += grid[i][j];
            }
        }
        
        long long topSum = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < m; j++) topSum += grid[i][j]; 
            long long botSum = total - topSum;
            if (topSum == botSum) return true;
            long long diff = topSum - botSum;
            long long target = abs(diff); 
            if (!mpp.count(target)) continue;
            
            for (auto& [r, c] : mpp[target]) {
                if (diff > 0 && isValidRemoval(r, c, 0, i, 0, m - 1)) return true;
                if (diff < 0 && isValidRemoval(r, c, i + 1, n - 1, 0, m - 1)) return true;
            }
        }
        
        long long leftSum = 0;
        for(int j = 0; j < m - 1; j++){
            for(int i = 0; i < n; i++) leftSum += grid[i][j]; 
            long long rightSum = total - leftSum;
            if (leftSum == rightSum) return true;
            long long diff = leftSum - rightSum;
            long long target = abs(diff);
            if (!mpp.count(target)) continue;
            
            for (auto& [r, c] : mpp[target]) {
                if (diff > 0 && isValidRemoval(r, c, 0, n - 1, 0, j)) return true;
                if (diff < 0 && isValidRemoval(r, c, 0, n - 1, j + 1, m - 1)) return true;
            }
        }
        
        return false;
    }
};