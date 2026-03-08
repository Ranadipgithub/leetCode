class Solution {
public:
    int solve(int i, int j, string &s, int cnt){
        if(cnt > 1) return 2;
        if(i >= j) return cnt;

        if(s[i] == s[j]){
            return solve(i+1, j-1, s, cnt);
        } 
        else {
            int cnt1 = solve(i+1, j, s, cnt+1);
            int cnt2 = solve(i, j-1, s, cnt+1);
            return min(cnt1, cnt2);
        }
    }

    bool validPalindrome(string s) {
        int cnt = solve(0, s.size()-1, s, 0);
        return cnt <= 1;
    }
};