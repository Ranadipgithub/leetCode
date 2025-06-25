class Solution {
public:
    long long countSmaller(vector<int>& nums1, vector<int>& nums2, long long val){
        int n = nums1.size(), m = nums2.size();
        long long cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums1[i] >= 0){
                long long low = 0, high = m - 1, idx = -1;
                while(low <= high){
                    long long mid = low + (high - low) / 2;
                    long long prod = 1LL * nums1[i] * nums2[mid];
                    if(prod <= val){
                        idx = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                cnt += (idx + 1);
            } else {
                long long low = 0, high = m - 1, idx = -1;
                while(low <= high){
                    long long mid = low + (high - low) / 2;
                    long long prod = 1LL * nums1[i] * nums2[mid];
                    if(prod <= val){
                        idx = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                if(idx == -1) {
                } else {
                    cnt += (m - idx);
                }
            }
        }
        return cnt;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n = nums1.size();
        int m = nums2.size();

        long long low = -10000000000LL, high = 10000000000LL;
        long long ans = 0;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long cnt = countSmaller(nums1, nums2, mid);
            if(cnt < k){
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};
