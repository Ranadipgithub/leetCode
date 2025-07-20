class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;
        unordered_map<char, int> freq;
        for (char c : s1) freq[c]++;
        int count = freq.size(); 
        int i = 0, j = 0;

        while (j < m) {
            if (freq.find(s2[j]) != freq.end()) {
                freq[s2[j]]--;
                if (freq[s2[j]] == 0) count--;
            }

            if (j - i + 1 < n) {
                j++;
            } else if (j - i + 1 == n) {
                if (count == 0) return true;

                if (freq.find(s2[i]) != freq.end()) {
                    if (freq[s2[i]] == 0) count++;
                    freq[s2[i]]++;
                }

                i++;
                j++;
            }
        }

        return false;
    }
};
