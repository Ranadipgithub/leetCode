class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> res;
        unordered_map<char, int> mpp;
        for(int i = 0;i<m;i++){
            mpp[p[i]]++;
        }
        unordered_map<char, int> copy = mpp;
        int i = 0, j = 0;
        while(j<n){
            if(mpp.find(s[j]) != mpp.end()){
                copy[s[j]]--;
                if(copy[s[j]] == 0) copy.erase(s[j]);
            }
            if(j-i+1 < m) j++;
            else if(j-i+1 == m){
                if(copy.size() == 0) res.push_back(i);
                if(mpp.find(s[i]) != mpp.end()){
                    copy[s[i]]++;
                    if(copy[s[i]] == 0) copy.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        return res;
    }
};