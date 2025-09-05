class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num2 >= num1) return -1;
        if(num1 == 0) return 0;
        int t = 1;
        while(true){
            long long temp = (long long)num1 - 1LL * t * num2;
            if(temp < 0) break;
            int cnt = __builtin_popcountll(temp);
            if(cnt <= t && t <= temp) return t;
            t++;
        }
        return -1;
    }
};