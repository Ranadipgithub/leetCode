class Solution {
public:
    int bs(vector<int>& potions, int num, long long success){
        int low = 0, high = potions.size() - 1;
        int ans = 0;
        bool fg = false;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(1LL * potions[mid] * num >= success){
                fg = true;
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return fg? potions.size()-ans: 0;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());

        vector<int> res(n, 0);
        for(int i = 0;i<n;i++){
            int cnt = bs(potions, spells[i], success);
            res[i] = cnt;
        }
        return res;
    }
};