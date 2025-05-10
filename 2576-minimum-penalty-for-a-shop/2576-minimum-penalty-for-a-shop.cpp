class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        int penalty = 0;
        for (char c : s) {
            if (c == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int bestTime = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'Y') penalty--; 
            else penalty++;            

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestTime = i + 1;
            }
        }

        return bestTime;
    }
};
