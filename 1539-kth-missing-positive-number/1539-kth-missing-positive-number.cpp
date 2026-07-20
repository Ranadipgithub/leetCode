class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int missing = arr[mid] - (mid+1);
            if(missing < k){
                low = mid + 1;
            } else high = mid - 1;
        }
        // ans = arr[high] + more = arr[high] + (k - (arr[high] - (high+1))) = k + high + 1 = low + k
        return low + k;
    }
};