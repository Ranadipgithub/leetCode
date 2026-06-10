class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mpp;
        for(int i = 0;i<s.size();i++){
            mpp[s[i]].push_back(i);
        }
        int cnt = 0;
        for(int i = 0;i<words.size();i++){
            bool fg = true;
            int prev = -1;
            for(int j = 0;j<words[i].size();j++){
                char ch = words[i][j];
                if(!mpp.count(ch)){
                    fg = false;
                    break;
                }
                auto it = upper_bound(mpp[ch].begin(), mpp[ch].end(), prev);
                if(it == mpp[ch].end()) {
                    fg = false;
                    break;
                }
                prev = *it;
            }
            if(fg) cnt++;
        }
        return cnt;
    }
};