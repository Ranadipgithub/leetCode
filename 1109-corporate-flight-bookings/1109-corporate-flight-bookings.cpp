class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+1, 0);
        for(auto &bkg: bookings){
            diff[bkg[0]-1] += bkg[2];
            diff[bkg[1]] -= bkg[2];
        }
        vector<int> res(n, 0);
        res[0] = diff[0];
        for(int i = 1;i<n;i++){
            res[i] = res[i-1] + diff[i];
        }
        return res;
    }
};