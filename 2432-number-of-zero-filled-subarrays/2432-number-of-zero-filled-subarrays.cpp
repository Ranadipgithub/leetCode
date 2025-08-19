class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        int firstIdx = -1, lastIdx = -1;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0){
                if(firstIdx == -1){
                    firstIdx = i;
                    lastIdx = i;
                } 
                else lastIdx = i;
            } else{
                long long len = 0;
                cout << firstIdx << " " << lastIdx << endl;
                if(firstIdx != -1)
                    len = lastIdx-firstIdx+1;
                cnt += (len*(len+1))/2;
                firstIdx = -1;
                lastIdx = -1;
            }
        }
        if(firstIdx != -1) {
            long long len = (lastIdx == -1 ? 1 : lastIdx - firstIdx + 1);
            cnt += (len * (len + 1)) / 2LL;
        }
        return cnt;
    }
};