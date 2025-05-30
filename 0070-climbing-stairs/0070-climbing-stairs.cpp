class Solution {
public:
    vector<int> memo = vector<int>(46, -1);
    int climbStairs(int n) {
        // if (n < 0) return 0;
        // if (n == 0) return 1;
        // if (memo[n] != -1) return memo[n];
        
        // int one = climbStairs(n - 1);
        // int two = climbStairs(n - 2);
        // return memo[n] = one + two;

        if( n == 1 || n == 2 || n == 3) return n;
        vector<int> t(n+1);
        t[0] = 0;
        t[1] = 1;
        t[2] = 2;
        for(int i = 3;i<=n;i++){
            t[i] = t[i-1]+t[i-2];
        }
        return t[n];
    }
};
