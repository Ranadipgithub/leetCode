class Solution {
public:
    int countMonobit(int n) {
        int cnt = 1;
        for(int i = 1;i<=n;i++){
            int wid = floor(log2(i)) + 1;
            cout << wid << endl;
            if(i == (1<<wid) - 1) cnt++;
        }
        return cnt;
    }
};