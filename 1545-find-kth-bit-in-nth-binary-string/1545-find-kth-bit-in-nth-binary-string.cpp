class Solution {
public:
    string invert(string s){
        string res = "";
        for(char ch: s){
            if(ch == '1') res += '0';
            else res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string solve(int n){
        if(n == 1) return "0";
        string temp = solve(n-1);
        return temp + '1' + invert(temp);
    }
    char findKthBit(int n, int k) {
        // 0
        // 011
        // 0111001
        // 011100110110001

        string res = solve(n);
        return res[k-1];
    }
};