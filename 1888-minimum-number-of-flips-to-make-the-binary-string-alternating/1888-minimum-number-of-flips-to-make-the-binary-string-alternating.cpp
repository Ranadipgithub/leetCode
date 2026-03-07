class Solution {
public:
    int minFlips(string s) {
        // 1011011
        int n = s.size();
        s += s;
        string s1, s2;
        for(int i = 0;i<2*n;i++){
            s1 += (i%2 == 0)? '0' : '1';
            s2 += (i%2 == 0)? '1' : '0';
        }
        int i = 0, j = 0;
        int f1 = 0, f2 = 0;
        int mini = INT_MAX;
        while(j<2*n){
            if(s[j] != s1[j]) f1++;
            if(s[j] != s2[j]) f2++;

            if(j-i+1 > n){
                if(s[i] != s1[i]) f1--;
                if(s[i] != s2[i]) f2--;

                i++;
            }
            if(j-i+1 == n){
                mini = min(mini, min(f1, f2));
            }
            j++;
        }
        return mini;
    }
};