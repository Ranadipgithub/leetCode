class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int mini = INT_MAX;
        for(int i = 0;i<n;i++){
            mini = min(mini, (int)strs[i].size());
        }
        string res;
        for(int i = 0;i<mini;i++){
            char temp = strs[0][i];
            for(int j = 0;j<n;j++){
                if(strs[j][i] != temp) return res;
            }
            res += temp;
        }
        return res;
    }
};