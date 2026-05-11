class Solution {
public:
    double findPower(double a, long long b) {
        if(b == 0) return 1;
        double half = findPower(a, b/2);
        double res = (half * half);
        if(b%2 == 1) res = (res * a);
        return res;
    }
    double myPow(double x, int n) {
        if(n < 0) return findPower(1/x, -(long long)n);
        return findPower(x, (long long)n);
    }
};