class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        for(int i = 1;i<n;i+=2){
            res[i-1] = -i;
            res[i] = i;
        }
        return res;
    }
};