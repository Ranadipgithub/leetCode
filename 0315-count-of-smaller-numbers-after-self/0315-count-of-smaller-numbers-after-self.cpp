class Solution {
public:
    void merge(vector<pair<int, int>> &v, int low, int mid, int high, vector<int>&cnt){
        vector<pair<int, int>> temp(high-low+1);
        int i = low, j = mid + 1, k = 0;
        while(i <= mid && j <= high){
            if (v[i].first > v[j].first) {  
                cnt[v[i].second] += (high - j + 1);
                temp[k++] = v[i++];
            } else {
                temp[k++] = v[j++];
            }
        }
        while(i <= mid){
            temp[k++] = v[i++];
        }
        while(j <= high){
            temp[k++] = v[j++];
        }
        for(int i = low;i<=high;i++){
            v[i] = temp[i - low];
        }
    }
    void mergesort(vector<pair<int, int>> &v, int low, int high, vector<int>&cnt){
        if(low >= high) return;
        int mid = low + (high - low)/2;
        mergesort(v, low, mid, cnt);
        mergesort(v, mid+1, high, cnt);
        merge(v, low, mid, high, cnt);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> v;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            v.push_back({nums[i], i});
        }
        vector<int> cnt(n, 0);
        mergesort(v, 0, n-1, cnt);
        return cnt;
    }
};