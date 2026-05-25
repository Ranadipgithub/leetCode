class Solution {
public:
    int getPrimeSum(int n){
        int sum = 0;
        while(n%2 == 0) {
            sum += 2;
            n = n/2;
        }
        for(int i = 3;i*i<=n;i+=2){
            while(n%i == 0){
                sum += i;
                n /= i;
            }
        }
        if(n > 2) sum += n;
        return sum;
    }
    bool isPrime(int n){
        if(n == 2) return true;
        if(n == 3) return true;
        if(n <= 1) return false;
        for(int i = 2;i*i<=n;i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    int smallestValue(int n) {
        int sum = n, prev = -1;
        while(true){
            prev = sum;
            sum = getPrimeSum(sum);
            if(prev == sum) break;
        }
        return sum;
    }
};