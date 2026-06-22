class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mpp;
        for(char &ch: text) mpp[ch]++;
        string str = "balon";
        int ans = INT_MAX;
        for(int i = 0;i<5;i++){
            if(!mpp.count(str[i])) return 0;
            if(mpp['l'] < 2 || mpp['o'] < 2) return 0;
            if(str[i] == 'l' || str[i] == 'o'){
                ans = min(ans, mpp[str[i]]/2);
            } else ans = min(ans, mpp[str[i]]);
        }
        return ans == INT_MAX? 0: ans;
    }
};