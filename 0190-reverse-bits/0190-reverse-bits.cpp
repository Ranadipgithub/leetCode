class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        for(int pos = 31;pos>=0;pos--){
            if(((1<<pos)&n) != 0){
                ans += 1 << (31-pos);
            } 
        }
        return ans;
    }
};