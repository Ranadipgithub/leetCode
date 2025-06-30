class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        int i = 0, j = 0, cnt = 0;
        while(j<n){
            mpp[s[j]]++;
            if(mpp.size() < 3){
                j++;
            } else {
                while(mpp.size() == 3){
                    cnt += n-j;
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 0) mpp.erase(s[i]);
                    i++; 
                }
                j++;
            }
        }
        return cnt;
    }
};