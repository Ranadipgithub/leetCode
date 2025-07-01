class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        if(n == 1)
            return true;
        
        return __builtin_popcount(n) == 1;
    }
};