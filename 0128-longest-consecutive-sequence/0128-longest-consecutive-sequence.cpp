class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        if(n == 0) return 0;
        int len = 1, maxLen = 1;
        for(int el: st){
            if(st.count(el-1)) continue;
            while(st.count(el+1)){
                len++;
                maxLen = max(maxLen, len);
                el = el + 1;
            }
            len = 1;
        }
        return maxLen;
    }
};