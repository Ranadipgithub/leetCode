class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        
        int zeros1 = count(nums1.begin(), nums1.end(), 0);
        int zeros2 = count(nums2.begin(), nums2.end(), 0);

        long long minSum1 = sum1 + zeros1;
        long long minSum2 = sum2 + zeros2;

        if (zeros1 == 0 && minSum2 > sum1) return -1;
        if (zeros2 == 0 && minSum1 > sum2) return -1;

        if (sum1 == sum2) {
            if (zeros1 != 0 && zeros2 != 0)
                return sum1 + max(zeros1, zeros2);
            else if (zeros1 != 0 || zeros2 != 0)
                return -1;
            else
                return sum1;
        }

        return max(minSum1, minSum2);
    }
};
