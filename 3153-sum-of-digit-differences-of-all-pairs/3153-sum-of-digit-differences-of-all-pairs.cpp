class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<string> snums(n);
        for(int i = 0;i<n;i++){
            snums[i] = to_string(nums[i]);
        }
        int size = snums[0].size();
        long long total = 0;
        for(int i = 0;i<size;i++){
            vector<int> mpp(10, 0);
            long long cnt = 0;
            for(int j = 0;j<n;j++){
                char ch = snums[j][i];
                cnt += j - mpp[ch-'0'];
                mpp[ch-'0']++;
            }
            total += cnt;
        }
        return total;
    }
};