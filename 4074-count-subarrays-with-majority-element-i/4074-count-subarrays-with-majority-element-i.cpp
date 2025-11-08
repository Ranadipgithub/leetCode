class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n= nums.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            unordered_map<int, int> fq;
            for(int j = i;j<n;j++){
                fq[nums[j]]++;
                if(fq[target] > (j-i+1)/2) cnt++;
            }
        }
        return cnt;
    }
};