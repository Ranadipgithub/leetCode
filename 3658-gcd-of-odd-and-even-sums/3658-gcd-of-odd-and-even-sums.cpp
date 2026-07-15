class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = 0, evenSum = 0;
        int oddCnt = 0, evenCnt = 0;
        int el = 1;
        while(oddCnt < n || evenCnt < n){
            if(oddCnt < n && el%2 == 1) {
                oddSum += el;
                oddCnt++;
            }
            if(evenCnt < n && el % 2 == 0){
                evenSum += el;
                evenCnt++;
            }
            el++;
        }
        return gcd(oddSum, evenSum);
    }
};