class Solution {
public:
    bool checkIfPangram(string s) {
        int n = s.size();
        if(n < 26) return false;
        vector<int> nums(26, 0);
        for(int i = 0;i<n;i++){
            nums[s[i] - 'a']++;
        }
        for(int i = 0;i<26;i++){
            if(nums[i] == 0) return false;
        }
        return true;
    }
};