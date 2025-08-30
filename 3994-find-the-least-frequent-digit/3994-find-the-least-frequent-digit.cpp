class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string str = to_string(n);
        int minFreq = INT_MAX;
        unordered_map<int, int> fq;
        for(char ch: str){
            fq[ch-'0']++;
        }
        for(auto it: fq){
            minFreq = min(minFreq, it.second);
        }
        int ans = INT_MAX;
        for(auto it: fq){
            if(it.second == minFreq){
                ans = min(ans, it.first);
            }
        }
        return ans;
    }
};