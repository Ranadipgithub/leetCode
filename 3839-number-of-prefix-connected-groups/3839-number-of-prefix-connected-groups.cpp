class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for(string word: words){
            if(word.size() < k) continue;
            string temp = word.substr(0, k);
            mpp[temp]++;
        }
        int cnt = 0;
        for(auto it: mpp){
            if(it.second > 1) cnt++;
        }
        return cnt;
    }
};