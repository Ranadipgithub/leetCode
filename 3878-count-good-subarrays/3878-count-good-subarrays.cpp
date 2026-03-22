class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        // bitwise or of an subarray will always be greater than or equal to the
        // maximum element of the subarray
        // so for this problem bitwise or of the subarray should be equal to the
        // maximum elemnt of the subarray to count it as a valid subarray
        // This means the all other elements will be a submask of the maxi element
        // meaning no other el will have bit 1 in a position where the maxi has 0

        // so for each nums[i] we have to check to the left and to the right that has
        // 1 bit whereas nums[i] has 0 bit

        int n = nums.size();
        vector<int> l(n, -1);
        vector<int> lastOne(32, -1);
        unordered_map<int, int> mpp;
        for(int i=0;i<n;i++){
            for(int j = 0;j<30;j++){
                if((nums[i] & (1 << j)) == 0){
                    l[i] = max(l[i], lastOne[j]);
                }
            }
            if(mpp.count(nums[i])){
                l[i] = max(l[i], mpp[nums[i]]);
            }
            for(int j = 0;j<30;j++){
                if((nums[i]&(1<<j)) != 0){
                    lastOne[j] = i;
                }
            }
            mpp[nums[i]] = i;
        }

        vector<int> r(n, n);
        vector<int> nextOne(32, n);
        for(int i = n-1;i>=0;i--){
            for(int j = 0;j<30;j++){
                if((nums[i]&(1<<j))==0){
                    r[i] = min(r[i], nextOne[j]);
                }
            }
            for(int j = 0;j<30;j++){
                if((nums[i]&(1<<j)) != 0){
                    nextOne[j] = i;
                }
            }
            mpp[nums[i]] = i;
        }

        long long cnt = 0;
        for(int i = 0;i<n;i++){
            int left = l[i], right = r[i];
            cnt += 1LL * (i-left)*(right-i);
        }
        return cnt;
    }
};