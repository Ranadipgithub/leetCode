class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        for(int i = 0;i < n;i++){
            mpp[s[i]]++;
        }
        int maxOddFq = 0, minEvenFq = n;
        for(auto it: mpp){
            int fq = it.second;
            if(fq % 2 == 1) maxOddFq = max(maxOddFq, fq);
            else minEvenFq = min(minEvenFq, fq);
        }
        return maxOddFq - minEvenFq;
    }
};