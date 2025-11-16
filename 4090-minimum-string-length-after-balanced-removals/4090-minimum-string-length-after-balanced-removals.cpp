class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n = s.size();
        int cnt1 =0, cnt2 = 0;
        for(char ch: s){
            if(ch == 'a') cnt1++;
            else cnt2++;
        }
        return abs(cnt1-cnt2);
    }
};