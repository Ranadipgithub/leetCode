class Solution {
public:
    const int MOD = 1e9 + 7;
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        for (int i = 0; i < n; i++) {
            string temp = to_string(nums[i]);
            reverse(temp.begin(), temp.end());
            res[i] = nums[i] - stoi(temp);
        }
        
        unordered_map<int, long long> freq;
        for (int x : res) freq[x]++;
        
        long long cnt = 0;
        for (auto& it : freq) {
            long long f = it.second;
            cnt = (cnt + f * (f - 1) / 2) % MOD;
        }
        
        return (int)cnt;
    }
};