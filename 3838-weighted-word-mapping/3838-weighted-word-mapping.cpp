class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for(string &word: words){
            int cnt = 0;
            for(char &ch: word){
                cnt += weights[ch-'a'];
            }
            cnt = cnt % 26;
            cout << cnt << " ";
            res += 'z' - cnt;
        }
        return res;
    }
};