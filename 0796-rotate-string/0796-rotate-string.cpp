class Solution {
public:
    // string rotate(string s, int k){
    //     int n = s.size();
    //     k = k%n;
    //     reverse(s.begin(), s.end());
    //     reverse(s.begin(), s.begin()+k+1);
    //     reverse(s.begin()+k+1, s.end());
    //     return s;
    // }
    bool rotateString(string s, string goal) {
        return s.length()==goal.length() && (s+s).contains(goal);
    }
};