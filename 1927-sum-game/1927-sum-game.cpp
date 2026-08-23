class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftSum = 0, leftCnt = 0;
        for(int i = 0;i<n/2;i++){
            if(num[i] == '?'){
                leftCnt++;
            } else leftSum += num[i]-'0';
        }
        int rightSum = 0, rightCnt = 0;
        for(int i = n/2;i<n;i++){
            if(num[i] == '?') rightCnt++;
            else rightSum += num[i] - '0';
        }
        if((leftCnt + rightCnt)%2 == 1) return true;
        if(2*leftSum + 9*leftCnt == 2*rightSum + 9*rightCnt) return false;
        return true;
    }
};