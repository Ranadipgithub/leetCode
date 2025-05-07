class Solution {
public:
    void merge(vector<int>&arr, int low, int mid, int high){
        int i = low, j = mid+1;
        vector<int> temp;
        while(i<=mid && j<= high){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            } else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= high) temp.push_back(arr[j++]);

        for (int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }
    }
    int countPairs(vector<int>&arr, int low, int mid, int high){
        int j = mid+1; int cnt = 0;
        for(int i = low;i<=mid;i++){
            while(j<=high && (long long)arr[i] > 2LL*arr[j]){
                j++;
            }
            cnt += (j-(mid+1));
        }
        return cnt;
    }
    int mergeSort(vector<int>&arr, int low, int high){
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = low + (high-low)/2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid+1, high);
        cnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = mergeSort(nums, 0, n-1);
        return ans;
    }
};