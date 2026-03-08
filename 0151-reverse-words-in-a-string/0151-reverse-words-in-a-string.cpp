class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> words;
        int i = -1,j = 0;
        while(j<n){
            if(s[j] == ' '){
                if(i != -1){
                    string temp = s.substr(i, j-i);
                    words.push_back(temp);
                    i = -1;
                }
            } else {
                if(i == -1) i = j;
            }
            j++;
        }
        if(i != -1){
            string temp = s.substr(i, j-i);
            words.push_back(temp);
        }
        reverse(words.begin(), words.end());
        string res = "";
        for(int i = 0;i<words.size();i++){
            res += words[i];
            if(i != words.size()-1) res += " ";
        }
        return res;
    }
};