class Solution {
public:
    bool solve(string s, string p){
        if(p.length() == 0){
            if(s.length() == 0) return true;
            else return false;
        }
        bool first_char_match = false;
        if(s.length() > 0 && (p[0] == s[0] || p[0] == '.')){
            first_char_match = true;
        }
        if(p[1] == '*'){
            bool not_take = solve(s, p.substr(2));
            bool take = first_char_match && solve(s.substr(1), p);
            return take || not_take;
        }

        return first_char_match && solve(s.substr(1), p.substr(1));

    }
    bool isMatch(string s, string p) {
        return solve(s, p);
    }
};