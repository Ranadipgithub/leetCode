class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prev = 0;
        string str = bank[0];
        for(int i = 0;i<str.size();i++){
            prev += str[i] == '1';
        }
        int cnt = 0;
        for(int i = 1;i<bank.size();i++){
            string temp = bank[i];
            int ones = 0;
            for(auto ch: temp) ones += ch == '1';
            if(ones != 0){
                cnt += prev * ones;
                prev = ones;    
            }
        }
        return cnt;
    }
};