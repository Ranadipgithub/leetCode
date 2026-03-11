class Solution {
public:
    long long minimumSteps(string s) {
        // 100
        // 011
        // 110100
        // 110001 => 2 steps to move 1 to the back
        // 100011 => 3 steps to move 1 to before last element
        // 000111 => again 3 steps;
        int n = s.size();
        long long cnt = 0;
        int i = n-1, j = n-1;
        for(int j = n-1;j>=0;j--){
            if(s[j] == '1'){
                cnt += i - j;
                i--;
            }
        }
        return cnt;
    }
};