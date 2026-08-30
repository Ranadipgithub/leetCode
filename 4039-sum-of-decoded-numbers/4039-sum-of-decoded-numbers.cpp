class Solution {
public:
    const int mod = 1e9+7;
    long long findPower(long long a, long long b) {
        if(b == 0) return 1;
        long long half = findPower(a, b/2);
        long long res = (half * half)%mod;
        if(b%2 == 1) res = (res * a)%mod;
        return res;
    }
    long long solve(long long num){
        int width = num%10;
        long long d = num/10;
        string s = to_string(d);
        string s1 = s.substr(0, width);
        string s2 = s.substr(width);
        int num1 = stoi(s1);
        int num2 = stoi(s2);
        return findPower(num1, num2) % mod;
    }
    int sumDecoded(vector<long long>& nums) {
        int sum = 0;
        for(long long &num: nums){
            sum = (sum + solve(num))%mod;
        }
        return sum%mod;
    }
};