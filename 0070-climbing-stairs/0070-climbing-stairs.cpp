class Solution {
public:
    vector<int> memo = vector<int>(46, -1);
    int climbStairs(int n) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        if (memo[n] != -1) return memo[n];
        
        int one = climbStairs(n - 1);
        int two = climbStairs(n - 2);
        return memo[n] = one + two;
    }
};
