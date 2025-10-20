class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            bool fg = false;
            for(int j = 0;j<n;j++){
                if(!used[j] && baskets[j] >= fruits[i]){
                    used[j] = true;
                    fg = true;
                    break;
                }
            }
            if(!fg) cnt++;
        }
        return cnt;
    }
};