class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                int x = i*i + j*j;
                double y = sqrt(x);
                if((int)y == y && y <= n) cnt++;
            }
        }
        return cnt;
    }
};