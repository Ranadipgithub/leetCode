class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        if (minSize > n) return 0;

        int i = 0, j = 0;
        unordered_map<char, int> fq;     
        unordered_map<string, int> cnt;   
        int maxCnt = 0;

        while(j<n) {
            fq[s[j]]++;

            if (j - i + 1 > minSize) {
                fq[s[i]]--;
                if (fq[s[i]] == 0) {
                    fq.erase(s[i]);
                }
                i++; 
            }

            if (j - i + 1 == minSize) {
                if (fq.size() <= maxLetters) {
                    string sub = s.substr(i, minSize);
                    cnt[sub]++;
                    maxCnt = max(maxCnt, cnt[sub]);
                }
            }
            j++;
        }

        return maxCnt;
    }
};