class Solution {
public:
    const int mod = 1e9+7;
    int concatenatedBinary(int n) {
        long long res = 0, power = 1;
        for(int i = n;i>=1;i--){
            int num = i;
            while(num > 0){
                int bit = num%2;
                res = (res + (long long)bit * power)%mod;
                power = (power * 2)%mod;
                num /= 2;
            }
        }
        return (int)res;
    }
};