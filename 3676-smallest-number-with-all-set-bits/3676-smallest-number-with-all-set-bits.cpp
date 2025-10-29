class Solution {
public:
    int smallestNumber(int n) {
        int idx = 0;
        for (int i = 0; i < 31; i++) {
            if ((n & (1 << i)) != 0) {
                idx = i;
            }
        }
        
        int sum = 0;
        for (int i = 0; i <= idx; i++) {
            if ((n & (1 << i)) == 0) {
                sum += 1 << i;
            }
        }
        
        return n + sum;
    }
};