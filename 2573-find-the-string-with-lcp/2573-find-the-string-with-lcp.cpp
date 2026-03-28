class Solution { 
public:
    vector<vector<int>> findLCP(string s){
        int n = s.length();
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        for (int j = 0; j < n; j ++) {
            result[n-1][j] = result[j][n-1] = (s[j] == s[n-1])? 1 : 0; 
        }
        for (int i = n-2; i >= 0; i --) {
            for (int j = n-2; j >= 0; j --) {
                result[i][j] = (s[i] == s[j])? 1 + result[i+1][j+1] : 0;
            }
        }
        return result;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string result (n, 'a');
        for (int i = 1; i < n; i ++) {
            vector<bool> nq(26, false);
            bool fg = false;
            
            for (int j = 0; j < i; j ++) {
                if (lcp[j][i] == 0) {
                    nq[result[j] - 'a'] = true;
                    continue;
                }
                fg = true;
                result[i] = result[j];
                break;
            }
        
            if (fg) continue;
            for (int j = 0; j < 26; j ++) {
                if (nq[j]) continue;
                result[i] = (char)('a' + j);
                break;
            }
        }
        
        if (findLCP(result) == lcp) return result;
        return "";
    }
};