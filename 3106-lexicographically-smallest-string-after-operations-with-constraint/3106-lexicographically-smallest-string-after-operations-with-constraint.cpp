class Solution {
public:
    int findDist(char ch1, char ch2){
        int d = abs(ch1 - ch2);
        return min(d, 26-d);
    }
    string solve(int idx, string &s, int k){
        if(idx == s.size()) return s;
        for(char ch = 'a'; ch <= 'z'; ch++){
            int dist = findDist(s[idx], ch);
            if(k-dist >= 0){
                string temp = s;
                temp[idx] = ch;
                string res = solve(idx+1, temp, k-dist);
                if(!res.empty()) return res;
            }
        }
        return "";
    }
    string getSmallestString(string s, int k) {
        return solve(0, s, k);
    }
};