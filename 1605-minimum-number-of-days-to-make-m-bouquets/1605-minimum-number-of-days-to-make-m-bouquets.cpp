class Solution {
private:
    bool possible(vector<int>& arr, int day, int m, int k){
        int count = 0;
        int noOfBouq = 0;
        for(int i = 0;i<arr.size();i++){
            if(day>=arr[i]){
                count++;
            }
            else{
                noOfBouq += count/k;
                count = 0;
            }
        }
        noOfBouq += count/k;
        return noOfBouq>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n/m < k) return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            mini = min(bloomDay[i],mini);
            maxi = max(bloomDay[i],maxi);
        }
        int low = mini, high = maxi;
        int ans = INT_MAX;
        while(low <= high){
            int mid = low +(high -low)/2;
            if(possible(bloomDay, mid, m, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans == INT_MAX? -1: ans;
    }
};