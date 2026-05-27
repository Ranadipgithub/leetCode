class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> last(26, 1e6);
        for(int i = 0;i<n;i++){
            if(islower(word[i])) last[word[i]-'a'] = i;
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(isupper(word[i])){
                int pos = last[word[i]-'A'];
                if(pos > i){
                    last[word[i]-'A'] = 1e6;
                } else{
                    last[word[i]-'A'] = 1e6;
                    cnt++;
                } 
            }
        }
        return cnt;
    }
};