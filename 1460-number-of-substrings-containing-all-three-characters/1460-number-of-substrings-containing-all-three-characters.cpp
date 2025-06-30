class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int a = 0, b = 0, c = 0;
        int cnt = 0;

        while (j < n) {
            if (s[j] == 'a') a++;
            else if (s[j] == 'b') b++;
            else c++;

            while (a > 0 && b > 0 && c > 0) {
                cnt += n - j;
                if (s[i] == 'a') a--;
                else if (s[i] == 'b') b--;
                else c--;
                i++;
            }

            j++;
        }

        return cnt;
    }
};
