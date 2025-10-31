class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        vector<int> res;
        for(int num: nums){
            if(mpp.count(num)){
                res.push_back(num);
            }
            mpp[num]++;
        } 
        return res;
    }
};