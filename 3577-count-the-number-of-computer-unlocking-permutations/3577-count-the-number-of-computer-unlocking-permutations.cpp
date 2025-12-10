class Solution {
public:
    const int mod = 1e9+7;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        for(int i = 1;i<n;i++){
            if(complexity[i] <= complexity[0]){
                return 0;
            }
        }
        long long res = 1;
        for(int i = 1;i<n;i++){
            res = (res * i )%mod;
            
        }
        return int(res);
    }
};