class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int cnt = 0;
        char next = '0';
        for(int i = 0;i<n;i++){
            if(s[i]!= next) cnt++;
            next = (next == '0') ? '1' : '0';
        }
        int mini = cnt;
        cnt = 0;
        next = '1';
        for(int i = 0;i<n;i++){
            if(s[i]!= next) cnt++;
            next = (next == '0') ? '1' : '0';
        }
        mini = min(mini, cnt);
        return mini;
    }
};