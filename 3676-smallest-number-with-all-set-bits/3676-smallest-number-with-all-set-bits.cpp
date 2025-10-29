class Solution {
public:
    int smallestNumber(int n) {
        int noOfBits = log2(n) + 1;
        return (1<<noOfBits)-1;
    }
};