class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        // int lastIdx = -1;
        for(int i = n-1;i>=0;i--){
            if((num[i] - '0')%2 == 1){
                // lastIdx =i;
                return num.substr(0, i+1);
                // break;
            }
        }
        // if(lastIdx == -1) return "";
        // string res = num.substr(0, lastIdx+1);
        // return res;
        return "";
    }
};