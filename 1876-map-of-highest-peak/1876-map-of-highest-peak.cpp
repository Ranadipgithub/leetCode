class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> height(n, vector<int>(m, -1));
        vector<vector<int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0,1}};

        queue<pair<int, int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(isWater[i][j] == 1){
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int, int> curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;
                for(auto &dir: direction){
                    int newi = i+dir[0];
                    int newj = j+dir[1];

                    if(newi >=0 && newi < n && newj >= 0 && newj < m && height[newi][newj] == -1){
                        height[newi][newj] = height[i][j]+1;
                        q.push({newi, newj});

                    }
                }
            }
        }
        return height;
    }
};