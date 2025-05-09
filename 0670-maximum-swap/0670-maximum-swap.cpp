class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        vector<int> maxi(n);
        maxi[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (s[i] - '0' > s[maxi[i + 1]] - '0') {
                maxi[i] = i;
            } else {
                maxi[i] = maxi[i + 1];
            }
        }

        for (int i = 0; i < n; i++) {
            if (s[i] < s[maxi[i]]) {
                swap(s[i], s[maxi[i]]);
                return stoi(s);
            }
        }

        return num;
    }
};
