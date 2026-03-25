class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();

        // 3 4 1 2 6 3 4 2
        // t t t t f t t f
        // 0 0 0 0 1 0 0 1
        // 0 0 0 0 1 1 1 2
        // 0 1 2 3 4 5 6 7
        vector<int> pre(n, 0);
        for(int i = 1;i<n;i++){
            if(nums[i]%2 + nums[i-1]%2 == 1){
                pre[i] = pre[i-1];
            } else {
                pre[i] = pre[i-1] + 1;
            }
        }
        vector<bool> res;
        for(auto it: queries){
            int s = it[0], e = it[1];
            if(pre[e]-pre[s] != 0) res.push_back(false);
            else res.push_back(true);
        }
        return res;
    }
};