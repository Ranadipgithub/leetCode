class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        int maxi = 1;
        for(int i = 0;i<n;i++){
            if(mpp.count(arr[i]-diff)){
                maxi = max(maxi, mpp[arr[i]-diff] + 1);
                mpp[arr[i]] = mpp[arr[i]-diff] + 1;
            }
            else mpp[arr[i]] = 1;
        }
        return maxi;
    }
};