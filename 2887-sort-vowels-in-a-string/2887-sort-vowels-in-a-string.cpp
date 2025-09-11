class Solution {
public:
    bool isvowel(char ch){
        if(ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U') return true;
        return false;
    }
    string sortVowels(string s) {
        string vowels = "";
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(isvowel(s[i])) vowels += s[i];
        }
        sort(vowels.begin(), vowels.end());
        int j = 0;
        string res = "";
        for(int i = 0;i<n;i++){
            if(isvowel(s[i])) {
                s[i] = vowels[j++];
            }
        }
        return s;
    }
};