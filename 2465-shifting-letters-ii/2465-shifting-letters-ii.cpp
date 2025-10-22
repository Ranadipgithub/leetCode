class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> arr(n+1, 0);
        for(auto it: shifts){
            int l = it[0], r = it[1], fg = it[2];
            if(fg == 1){
                arr[l]++;
                arr[r+1]--;
            } else {
                arr[l]--;
                arr[r+1]++;
            }
        }

        for(int i = 1;i<n;i++){
            arr[i] = arr[i] + arr[i-1];
        }

        for(int i = 0;i<n;i++){
            int temp = ((s[i]-'a')+arr[i])%26;
            if(temp < 0) temp += 26;
            s[i] = temp + 'a';
        }
        return s;
    }
};