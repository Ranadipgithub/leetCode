class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        long long sum = 0, mult = 1;
        while(n > 0){
            int dig = n % 10;
            sum += dig;
            mult *= dig;
            n /= 10;
        }
        cout << sum << " " << mult << endl;
        return num % (sum + mult) == 0;
    }
};