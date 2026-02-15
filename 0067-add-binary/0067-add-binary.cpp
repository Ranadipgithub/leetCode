class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int n = a.size(), m = b.size();
        int i = n-1, j = m-1, carry = 0;
        while(i>=0 || j >= 0){
            int sum = 0;
            if(i>=0){
                sum += a[i]-'0';
            }
            if(j>=0){
                sum += b[j]-'0';
            }
            sum += carry;
            if(sum == 2){
                res += '0';
                carry = 1;
            } else if(sum == 3){
                res += '1';
                carry = 1;
            } else {
                res += to_string(sum);
                carry = 0;
            }
            i--;
            j--;
        }
        if(carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};