class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        map<char, int> mpp;
        for(char ch: s){
            mpp[ch]++;
        }
        string res = "";
        for(int i = n-1;i>=0;i--){
            map<char, int> temp = mpp;
            bool fg = true;
            for(int k = 0;k<i;k++){
                if(temp[target[k]] > 0){
                    temp[target[k]]--;
                } else {
                    fg = false;
                    break;
                }
            }
            if(!fg) continue;
            for(char c = target[i]+1;c<='z';c++){
                if(temp.count(c) && temp[c] > 0){
                    string res = target.substr(0, i);
                    res += c;
                    temp[c]--;
                    for(auto it: temp){
                        res += string(it.second, it.first);
                    }
                    return res;
                }
            }
        }
        return "";
    }
};