class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        long long num = (long long)n;
        return (num&(num-1)) == 0;
    }
};