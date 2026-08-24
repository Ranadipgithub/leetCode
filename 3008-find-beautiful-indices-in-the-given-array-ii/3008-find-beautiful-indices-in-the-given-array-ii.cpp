class Solution {
public:
    void findLps(vector<int>&lps, string &s){
        int pre = 0, suff = 1;
        while(suff < s.size()){
            if(s[pre] == s[suff]){
                lps[suff] = pre + 1;
                pre++;
                suff++;
            } else {
                if(pre == 0) suff++;
                else pre = lps[pre-1];
            }
        }
    }
    vector<int> search(string &pat, string &txt){
        vector<int> lps(pat.size(), 0);
        findLps(lps, pat);
        int first = 0, second = 0;
        vector<int> res;
        while(first < txt.size()){
            if(txt[first] == pat[second]){
                first++;
                second++;
                if(second == pat.size()){
                    res.push_back(first-pat.size());
                    second = lps[second-1];
                }
            } else {
                if(second == 0) first++;
                else {
                    second = lps[second-1];
                }
            }
        }
        return res;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> indices1 = search(a, s);
        vector<int> indices2 = search(b, s);
        // for(auto it: indices1) cout << it << endl;
        // for(auto it: indices2) cout << it << endl;
        vector<int> res;
        // 16 33
        // 4  18
        // 0 2
        // 0 2
        for(int i = 0;i<indices1.size();i++){
            auto it = lower_bound(indices2.begin(), indices2.end(), indices1[i]);
            if(it != indices2.end()){
                int diff = abs(*it - indices1[i]);
                if(diff <= k){
                    res.push_back(indices1[i]);
                    continue;
                } 
            }
            if(it != indices2.begin()){
                --it;
                int diff = abs(*it - indices1[i]);
                if(diff <= k) res.push_back(indices1[i]);
            }
        }
        return res;
    }
};