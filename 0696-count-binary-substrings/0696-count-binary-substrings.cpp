class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int zeros = 0, ones = 0;
        vector<int> res;
        for(int i = 0;i<n;i++){
            if(s[i] == '1'){
                if(zeros > 0) res.push_back(zeros);
                zeros = 0;
                ones++;
            } else {
                if(ones > 0) res.push_back(ones);
                ones = 0;
                zeros++;
            }
        }
        if(zeros > 0) res.push_back(zeros);
        else if(ones > 0) res.push_back(ones);
        int cnt = 0;
        for(int i = 1;i<res.size();i++){
            cnt += min(res[i], res[i-1]);
        }
        return cnt;
    }
};