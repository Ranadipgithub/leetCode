class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long ans = 0;
        if(s.length() == 0) return 0;
        while(i < s.size() && s[i] == ' '){
            i++;
        }
        s = s.substr(i);
        int sign = +1;
        if(s[0] == '-'){
            sign = -1;
        }
        int maxi = INT_MAX, mini = INT_MIN;
        i = (s[0] == '+' || s[0] == '-')? 1 : 0;
        while(i < s.length()){
            if(!(isdigit(s[i]))) break;
            ans = ans*10 + (s[i] - '0');
            if(sign == -1 && -1*ans  < mini) return mini;
            if(sign == 1 && 1*ans > maxi) return maxi;
            i++;
        }
        return (int)(sign*ans);
    }
};