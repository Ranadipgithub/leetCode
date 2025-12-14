class Solution {
public:
    const int MOD = 1e9+7;
    int numberOfWays(string s) {
        int n = s.size();
        vector<int> seats;
        for(int i = 0;i<n;i++){
            if(s[i] == 'S') seats.push_back(i);
        }

        if(seats.size() == 0 || seats.size()%2 == 1) return 0;

        long long cnt = 1;
        for(int i = 2;i<seats.size();i+=2){
            cnt = (cnt * (seats[i]-seats[i-1]))%MOD;
        }
        return (int)cnt;
    }
};