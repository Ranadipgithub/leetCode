class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char c : word)
            freq[c]++;
        
        vector<int> counts;
        for (auto& [c, f] : freq)
            counts.push_back(f);
        
        sort(counts.begin(), counts.end());
        
        int minDel = INT_MAX;
        int n = counts.size();
        
        for (int i = 0; i < n; ++i) {
            int base = counts[i];
            int deletions = 0;
            
            for (int j = 0; j < i; ++j)
                deletions += counts[j];
            
            for (int j = i + 1; j < n; ++j) {
                if (counts[j] > base + k)
                    deletions += counts[j] - (base + k);
            }
            
            minDel = min(minDel, deletions);
        }
        
        return minDel == INT_MAX ? 0 : minDel;
    }
};
