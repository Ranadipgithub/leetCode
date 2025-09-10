class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> st;
        for(auto &it : friendships) {
            int u = it[0] - 1;
            int v = it[1] - 1;
            unordered_set<int> st1(begin(languages[u]), end(languages[u]));
            bool fg = false;
            for(int lang : languages[v]) {
                if(st1.count(lang)) {
                    fg = true;
                    break;
                }
            }
            if(!fg) {
                st.insert(u);
                st.insert(v);
            }
        }
        vector<int> language(n+1, 0);
        int cnt = 0;
        for(int user : st) {
            for(int lang : languages[user]) {
                language[lang]++;
                cnt = max(cnt, language[lang]);
            }
        }
        return st.size() - cnt;
    }
};