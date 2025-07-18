class Solution {
public: 
    
    int solve(int n){
        if(n == 0 || n == 1) return 1;
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            int numsLeft = i-1;
            int numsRight = n-i;
            cnt += solve(numsLeft) * solve(numsRight);
        }
        return cnt;
    }
    int numTrees(int n) {
        return solve(n);
    }
};