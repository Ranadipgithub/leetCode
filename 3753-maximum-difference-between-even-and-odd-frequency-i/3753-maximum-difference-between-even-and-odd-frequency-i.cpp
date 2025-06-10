class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        unordered_map<char, int> fq;
        for(int i = 0;i<n;i++){
            fq[s[i]]++;
        }
        int maxiOdd = 0, maxiEven = 0, miniEven = INT_MAX, res = INT_MIN;
        for(auto it: fq){
            if(it.second%2 == 1) maxiOdd = max(maxiOdd, it.second);
            else{
                // maxiEven = max(maxiEven, it.second);
                miniEven = min(miniEven, it.second);
            } 
            
        }
        // return max(maxiOdd-miniEven, maxiOdd-maxiEven);
        return maxiOdd-miniEven;
    }
};