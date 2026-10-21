class Solution {
public:
    int minOperations(string s) {
        // c d n a  a d c n  n c d a  
        // c d n a  a c d n  c d n a
        // c a d n           c a d n
        // a c d n           a c d n
        // if the first element is larger than the max of the substring from 1 to n-1 then 
        // else 
        int n = s.size();
        if(n == 2 && s[0] > s[1]) return -1;
        if(is_sorted(s.begin(), s.end())) return 0;
        
        char mch = *max_element(s.begin(), s.end());
        char lch = *min_element(s.begin(), s.end());
        
        if(lch == s[0] || mch == s[n-1]) return 1;
        if(mch == s[0] && lch == s[n-1] && count(s.begin(), s.end(), mch) == 1 && count(s.begin(), s.end(), lch) == 1) return 3;
        
        return 2;
    }
};