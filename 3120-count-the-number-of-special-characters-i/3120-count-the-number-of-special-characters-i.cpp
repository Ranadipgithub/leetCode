class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        unordered_set<char> st;
        vector<int> res(26, 0);
        for(int i = 0;i<n;i++){
            if(isupper(word[i])){
                if(st.count(tolower(word[i]))){
                    res[tolower(word[i])-'a'] = 1;
                    st.erase(tolower(word[i]));
                } else st.insert(word[i]);
            } else {
                if(st.count(toupper(word[i]))){
                    res[word[i]-'a'] = 1;
                    st.erase(toupper(word[i]));
                } else st.insert(word[i]);
            }
        }
        int sum = accumulate(res.begin(), res.end(), 0);
        return sum;
    }
};