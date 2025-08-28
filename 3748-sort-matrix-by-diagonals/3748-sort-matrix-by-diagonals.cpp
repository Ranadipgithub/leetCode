class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int, vector<int>> mpp;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                mpp[i-j].push_back(grid[i][j]);
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0 || j == 0){
                    vector<int> temp = mpp[i-j];
                    if(i-j >= 0){
                        sort(temp.begin(), temp.end(), greater<int>());
                    } else{
                        sort(temp.begin(), temp.end());
                    }
                    int newi = i, newj = j;
                    int k = 0;
                    while(newi <n && newj < n){
                        grid[newi][newj] = temp[k++];
                        newi++;
                        newj++;
                    }
                }
            }
        }
        return grid;
    }
};