class Solution {
public:
    void findLps(vector<int>&lps, string &s){
        int pre = 0, suff = 1;
        while(suff < s.size()){
            if(s[pre] == s[suff]){
                lps[suff] = pre +1;
                pre++;
                suff++;
            } else {
                if(pre == 0){
                    lps[suff] = 0;
                    suff++;
                } else {
                    pre = lps[pre-1];
                }
            }
        }
    }
    int search(string &pat, string &txt){
        int n = pat.size();
        vector<int> lps(n, 0);
        findLps(lps, pat);
        int first = 0, second = 0;
        int cnt = 0;
        while(first < txt.size()){
            if(txt[first] == pat[second]){
                first++;
                second++;
                if(second == pat.size()){
                    cnt++;
                    second = lps[second-1];
                }
            } else {
                if(second == 0) first++;
                else second = lps[second-1];
            }
        }
        return cnt;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        // nums[i+1] > nums[i]
        // nums[i+2] == nums[i+1]
        // nums[i+3] < nums[i+2]
        // 1 -> increasing, 0 -> same, -1 -> decreasing
        // 1 1 1 1 1 => pattern of 1 1 => 4
        // 1 0 2 1 1 0 2 => pattern of 1 0 2 => 2

        string s = "";
        s.reserve(nums.size());
        for(int i = 1;i<nums.size();i++){
            if(nums[i] > nums[i-1]){
                s += '1';
            } else if(nums[i] == nums[i-1]){
                s += '0';
            } else s += '2';
        }
        string pat = "";
        pat.reserve(pattern.size());
        for(int i = 0;i<pattern.size();i++){
            if(pattern[i] == -1) pat += '2';
            else pat += (pattern[i] + '0');
        }
        return search(pat, s);
    }
};