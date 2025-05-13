class Solution {
public:
    int mod = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<long long> freq(26, 0); 
        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int step = 0; step < t; step++) {
            vector<long long> nextFreq(26, 0);

            for (int i = 0; i < 25; i++) {
                nextFreq[i + 1] = (nextFreq[i + 1] + freq[i]) % mod;
            }

            nextFreq[0] = (nextFreq[0] + freq[25]) % mod;
            nextFreq[1] = (nextFreq[1] + freq[25]) % mod;

            freq = move(nextFreq);
        }

        long long total = 0;
        for (int i = 0; i < 26; i++) {
            total = (total + freq[i]) % mod;
        }

        return total;
    }
};
