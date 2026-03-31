class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string res(n+m-1, '$');
        for(int i = 0;i<n;i++){
            if(str1[i] == 'T'){
                for(int j = i;j<i+m;j++){
                    if(res[j] == '$' || res[j] == str2[j-i]){
                        res[j] = str2[j-i];
                    } else return "";
                }
            }
        }
        unordered_set<int> st;
        for(int i = 0;i<res.size();i++) {
            if(res[i] == '$'){
                res[i] = 'a';
                st.insert(i);
            }
        }
        for(int i = 0;i<n;i++){
            if(str1[i] == 'F'){
                string temp = res.substr(i, m);
                if(temp != str2) continue;

                bool fg = false;
                for(int j = i+m-1;j>=i;j--){
                    if(st.count(j)){
                        for(char ch = 'b';ch<='z';ch++){
                            if(ch != str2[j-i]){
                                res[j] = ch;
                                fg = true;
                                break;
                            }
                        }
                    }
                    if(fg) break;
                }
                if(!fg) return "";
            }
        }
        return res;
    }
};