class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        unordered_map<char, int> mpp1;
        for(auto ch: s){
            mpp1[ch]++;
        }
        unordered_map<char, int> mpp2;
        int cnt = 0;
        for(int k = 0;k<=n-1;k++){
            mpp2[s[k]]++;
            mpp1[s[k]]--;
            if(mpp1[s[k]] == 0) mpp1.erase(s[k]);
            if(mpp1.size() == mpp2.size()) cnt++;
        }
        return cnt;
    }
};