class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> st;
        for(int i = 0;i<brokenLetters.size();i++){
            st.insert(brokenLetters[i]);
        }
        int sidx = 0, cnt = 0;
        for(int i = 0;i<text.size();i++){
            if(text[i] == ' '){
                string temp = text.substr(sidx, i-sidx);
                bool fg = false;
                for(char ch: temp){
                    if(st.find(ch) != st.end()){
                        fg = true;
                        break;
                    }
                }
                if(!fg) cnt++;
                sidx = i+1;
            }
        }

        string temp = text.substr(sidx);
        bool fg = false;
        for (char ch : temp) {
            if (st.find(ch) != st.end()) {
                fg = true;
                break;
            }
        }
        if (!fg) cnt++;

        return cnt;
    }
};