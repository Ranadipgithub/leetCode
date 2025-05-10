class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        // cout << sum1 << sum2;
        int zeros1 = 0, zeros2 = 0;
        for(int i = 0;i<nums1.size();i++){
            if(nums1[i] == 0) zeros1++;
        }
        for(int i = 0;i<nums2.size();i++){
            if(nums2[i] == 0) zeros2++;
        }
        if(zeros1 == 0 && (long long)zeros2+sum2 > sum1) return -1;
        if(zeros2 == 0 && (long long)zeros1+sum1 > sum2) return -1;
        if(sum1 == sum2){
            if(zeros1 != 0 && zeros2!=0)
                return (long long)sum1+max(zeros1, zeros2);
            else if(zeros1 != 0 || zeros2!=0) return -1;
            else return sum1;
        }
        else return max(sum2+zeros2, sum1+zeros1);
        return -1;
    }
};