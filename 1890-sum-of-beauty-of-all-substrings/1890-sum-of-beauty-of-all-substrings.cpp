class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            // string str = "";
            vector<int> temp(26, 0);
            for (int j = i; j < n; j++) {
                // str += s[j];
                temp[s[j] - 'a']++;
                int maxi = *max_element(temp.begin(), temp.end());
                int mini = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (temp[k] > 0) mini = min(mini, temp[k]);
                }
                ans += maxi - mini;
            }
        }
        return ans;
    }
};