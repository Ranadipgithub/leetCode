class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> suff(n, 0);
        int i = n-1, j = m - 1;
        int cnt = 0;
        while(i >= 0 && j >= 0){
            if(word1[i] == word2[j]){
                cnt++;
                suff[i--] = cnt;
                j--;
            } else {
                suff[i--] = cnt;
            }
        }
        for(int k = i;k>=0;k--) suff[k] = cnt;
        
        vector<int> res;
        i = 0, j = 0;
        bool canChange = true;
        while(i < n && j < m){
            if(word1[i] == word2[j]){
                res.push_back(i);
                i++;
                j++;
            } else {
                if(canChange && i+1 < n && suff[i+1] >= m-j-1){
                    canChange = false;
                    res.push_back(i);
                    i++;
                    j++;
                } else i++;
            }
        }
        if(j<m) return {};
        return res;
    }
};