class Solution {
public:
    long long findPower(int a, int b, int limit) {
        if(a == 0) return 0;
        if(b == 0) return 1;
        long long half = findPower(a, b/2, limit);
        if(half == -1) return -1;
        if (half > 0 && half > limit / half) return -1;
        long long res = (half * half);
        if(b%2 == 1){
            if (a > 0 && res > limit / a) return -1;
            res = (res * a);
        } 
        return res;
    }
    int countKthRoots(int l, int r, int k) {
        if(k == 1) return r-l+1;
        int cnt = 0;
        for(int i = 0;i*i<=r;i++){
            long long temp = findPower(i, k, r);
            if(temp == -1 || temp > r) {
                if(i > 1) break;
                else continue;
            }
            if(temp >= l) cnt++;
        }
        return cnt;
    }
};