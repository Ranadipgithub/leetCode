class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros;
        for(int i = 0;i<n;i++){
            int lastIdx = 0;
            for(int j = n-1;j>=0;j--){
                if(grid[i][j] == 1){
                    lastIdx = j;
                    break;
                }
            }
            zeros.push_back(n-lastIdx-1);
            cout << zeros[i] << " ";
        }
        
        int swaps = 0;
        for (int i = 0; i < n ; i++) {
            int target = n-i-1;
            int j = i;

            while(j<n && zeros[j] < target) j++;
            if(j >= n) return -1;

            while(j > i){
                swap(zeros[j], zeros[j-1]);
                swaps++;
                j--;
            }
        }
        
        return swaps;
    }
};