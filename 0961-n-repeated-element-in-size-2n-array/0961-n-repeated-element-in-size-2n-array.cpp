class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> fq;
        int n = nums.size();
        for(int num: nums){
            fq[num]++;
            if(fq[num] == n/2) return num;
        }
        return -1;
    }
};