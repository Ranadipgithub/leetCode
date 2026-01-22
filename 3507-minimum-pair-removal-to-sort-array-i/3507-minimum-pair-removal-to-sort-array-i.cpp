class Solution {
private:
    bool is(vector<int> &a){
        bool fg = true;
        for(int i = 0;i<a.size()-1;i++){
            if(a[i] > a[i+1]){
                fg = false;
            }
        }
        return fg;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n= nums.size();
        int cnt = 0;
        while(!is(nums)){
            int idx = -1;
            int mini = INT_MAX;
            int n = nums.size();
            for(int i = 0;i<n-1;i++){
                if((nums[i] + nums[i+1]) < mini){
                    mini = nums[i] + nums[i+1];
                    idx = i;
                }
            }
            nums[idx] = mini;
            nums.erase(nums.begin()+(idx+1));
            cnt++;
        }
        return cnt;
    }
};