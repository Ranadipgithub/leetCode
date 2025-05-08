class Solution {
public:
    int minimumRefill(vector<int>& arr, int capacityA, int capacityB) {
        int n = arr.size();
        int i = 0, j = n-1;
        int cnt = 0;
        int remA=capacityA, remB = capacityB;
        while(i<j){
            if(arr[i]<=remA){
                remA = remA-arr[i];
            } else{
                cnt++;
                remA = capacityA - arr[i];
                
            }
            i++;
            if(arr[j]<=remB){
                remB = remB-arr[j];
            } else{
                cnt++;
                remB = capacityB - arr[j];
                
            }
            j--;
        }
        if(i == j){
            if(remA < arr[i] && remB < arr[j]){
                cnt++;
            }
        }
        return cnt;
    }
};