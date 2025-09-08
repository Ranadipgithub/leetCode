class Solution {
public:
    bool containzero(int n){
        while(n){
            int temp = n%10;
            if(temp == 0) return true;
            n = n/10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        for(int i = 1;i<=n;i++){
            if(containzero(i) || containzero(n-i)) continue;
            else {
                res.push_back(i);
                res.push_back(n-i);
                break;
            }
        }
        return res;
    }
};