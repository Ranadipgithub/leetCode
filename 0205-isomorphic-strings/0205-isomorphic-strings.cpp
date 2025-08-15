class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        int mapST[256] = {0}; // s -> t
        int mapTS[256] = {0}; // t -> s

        for (int i = 0; i < s.size(); i++) {
            unsigned char cs = s[i], ct = t[i];
            if (mapST[cs] == 0 && mapTS[ct] == 0) {
                mapST[cs] = ct;
                mapTS[ct] = cs;
            } 
            else if (mapST[cs] != ct || mapTS[ct] != cs) {
                return false;
            }
        }
        return true;
    }
};
