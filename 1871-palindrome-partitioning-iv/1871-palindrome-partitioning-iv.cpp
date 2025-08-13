class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<int>> t(n, vector<int>(n, 0));
        for(int l = 1;l<=n;l++){
            for(int i = 0;i+l-1<n;i++){
                int j = i+l-1;
                if(i == j) t[i][j] = true;
                else if(i+1 == j) t[i][j] = s[i] == s[j];
                else t[i][j] = (s[i] == s[j]) && t[i+1][j-1];
            }
        }

        vector<int> pre(n, 0);
        for(int i = 0;i<n;i++){
            if(t[0][i]) pre[i] = 1;
        }
        vector<int> suff(n, 0);
        for(int i = 0;i<n;i++){
            if(t[i][n-1]) suff[i] = 1;
        }

        // for(auto it: pre) cout << it << " ";
        // cout << endl;
        // for(auto it: suff) cout << it << " ";

        for(int i = 0;i<n;i++){
            for(int j = n-1;j>=0;j--){
                if(pre[i] == 0) break;
                if(pre[i] == 1 && suff[j] == 1){
                    if(t[i+1][j-1]) return true;
                }
            }
        }
        return false;
    }
};