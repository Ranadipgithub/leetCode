class Solution {
public:
    void merge(vector<long long>& arr, long long low, long long mid, long long high) {
    long long i = low, j = mid + 1;
    vector<long long> temp;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= high) temp.push_back(arr[j++]);

    for (long long k = low; k <= high; k++) {
        arr[k] = temp[k - low];
    }
}

long long countPairs(vector<long long>& arr, long long low, long long mid, long long high, long long lower, long long upper) {
    long long cnt = 0;
    long long l = mid + 1, r = mid + 1;
    for(long long i = low;i<=mid;i++){
        while(l<=high && arr[l] - arr[i] < lower) l++;
        while(r <= high && arr[r] - arr[i] <= upper) r++;
        cnt += (r - l);
    }
    return cnt;
}

long long mergeSort(vector<long long>& arr, long long low, long long high, long long lower, long long upper) {
    long long cnt = 0;
    if (low >= high) return cnt;
    long long mid = low + (high - low) / 2;
    cnt += mergeSort(arr, low, mid, lower, upper);
    cnt += mergeSort(arr, mid + 1, high, lower, upper);
    cnt += countPairs(arr, low, mid, high, lower, upper);
    merge(arr, low, mid, high);
    return cnt;
}
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (long long i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        long long ans = mergeSort(prefixSum, 0, n, lower, upper);
        return ans;
    }
};