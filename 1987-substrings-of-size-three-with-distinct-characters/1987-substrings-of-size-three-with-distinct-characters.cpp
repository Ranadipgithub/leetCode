class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int cnt = 0;
        unordered_map<char, int> mpp;
        while(j<n){
            mpp[s[j]]++;
            if(j-i+1<3) j++;
            else if(j-i+1 == 3){
                if(mpp.size() == 3) cnt++;
                if(mpp.count(s[i])) mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
                j++;
            }
        }
        return cnt;
    }
};