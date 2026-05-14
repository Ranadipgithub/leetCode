class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> fq(maxi+1, 0);
        for(int num: nums) fq[num]++;
        for(int i = 1;i<maxi;i++){
            if(fq[i] != 1) return false;
        }
        return fq[maxi] == 2;
    }
};