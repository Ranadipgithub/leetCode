class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0, cnt=0;
        if(n == 0) return 1;
        while(n > 0){
            int rem = n%2;
            ans += (1-rem)*(1<<cnt);
            n = n/2;
            cnt++;
        }
        return ans;
    }
};