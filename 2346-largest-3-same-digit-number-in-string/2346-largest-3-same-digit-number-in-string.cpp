class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int maxi = -1;
        for (int i = 0; i <= n - 3; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                int digit = num[i] - '0';
                maxi = max(maxi, digit);
            }
        }
        if (maxi == -1) return "";
        return string(3, maxi + '0');
    }
};