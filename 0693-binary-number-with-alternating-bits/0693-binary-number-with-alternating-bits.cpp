class Solution {
public:
    bool hasAlternatingBits(int n) {
        int cnt = 31 - __builtin_clz(n);
        int curr = 1 & n;
        int next = 1 - curr;

        for(int i = 1; i <= cnt; i++){
            if(((n >> i) & 1) != next){
                return false;
            }
            next = 1 - next;
        }
        return true;
    }
};