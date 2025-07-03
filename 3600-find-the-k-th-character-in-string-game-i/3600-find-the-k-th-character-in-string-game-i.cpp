class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.length() <= k) {  
            string temp = s;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == 'z') temp += 'a';
                else temp += s[i] + 1;  
            }
            s = temp;
            cout << s << endl;
        }
        return s[k-1];  
    }
};
