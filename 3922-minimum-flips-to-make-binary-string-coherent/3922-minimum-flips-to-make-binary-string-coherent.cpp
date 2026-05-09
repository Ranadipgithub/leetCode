class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        // all zero
        // all one
        // 000100000
        // 100000001
        if(n < 3) return 0;
        int ones = count(s.begin(), s.end(), '1');
        int zeros = n - ones;

        int c1 = ones;
        int c2 = zeros;
        int c3 = (ones >= 1 ? ones - 1 : INT_MAX);
        int c4 = (s[0] == '1' && s[n-1] == '1' && ones >= 2 ? ones - 2 : INT_MAX);
        return min({c1, c2, c3, c4});
    }
};