class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxlen = 1;
        for(int i = 0;i<n;i++){
            vector<int> freq(26, 0);
            for(int j = i;j<n;j++){
                freq[s[j]-'a']++;
                int temp = freq[s[j] - 'a'];
                bool fg = true;
                for(int k = 0;k<26;k++){
                    if(freq[k] > 0 && freq[k] != temp) fg = false;
                }
                if(fg){
                    maxlen = max(maxlen, j-i+1);
                }
            }
        }
        return maxlen;
    }
};