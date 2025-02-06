class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mpp;
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(mpp.find(nums[i]*nums[j]) != mpp.end()){
                    count += mpp[nums[i]*nums[j]]*8;
                }
                mpp[nums[i]*nums[j]]++;
            }
        }
        return count;
    }
};