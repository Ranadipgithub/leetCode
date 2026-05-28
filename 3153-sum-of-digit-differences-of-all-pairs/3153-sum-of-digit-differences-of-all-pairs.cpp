class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        string str = to_string(nums[0]);
        int size = str.size();
        long long total = 0;
        for(int i = 0;i<size;i++){
            unordered_map<char, int> mpp;
            long long cnt = 0;
            for(int j = 0;j<n;j++){
                string str = to_string(nums[j]);
                char ch = str[i];
                cnt += j - mpp[ch];
                mpp[ch]++;
            }
            total += cnt;
        }
        return total;
    }
};