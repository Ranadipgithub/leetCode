class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0;i<n;i++){
            if(pq.size() >= k){
                if(pq.top() < nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                    continue;
                }
            } else pq.push(nums[i]);
        }
        return pq.top();
    }
};