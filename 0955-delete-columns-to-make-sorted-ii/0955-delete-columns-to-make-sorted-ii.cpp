class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size(); 
        int cols = strs[0].size(); 
        int cnt = 0;
        vector<bool> alreadySorted(rows, false);
        
        for(int j = 0; j < cols; j++) {
            bool fg = false;
            for(int i = 0; i < rows-1; i++) {
                if(!alreadySorted[i] && strs[i][j] > strs[i+1][j]) {
                    cnt++;
                    fg = true;
                    break;
                }
            }

            if(fg) {
                continue;
            }

            for(int i = 0; i < rows-1; i++) {
                alreadySorted[i] = alreadySorted[i] | (strs[i][j] < strs[i+1][j]);
            }

        }

        return cnt;
    }
};