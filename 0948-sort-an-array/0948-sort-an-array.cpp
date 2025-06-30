class Solution {
private:
    void insert(vector<int>& nums, int temp){
        int n = nums.size();
        if(n == 0 || nums[n - 1] <= temp){
            nums.push_back(temp);
            return;
        }
        int val = nums[n - 1];
        nums.pop_back();
        insert(nums, temp);
        nums.push_back(val);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums;
        // if(n == 1 || n == 0) return nums;
        // int temp = nums[n-1];
        // nums.pop_back();
        // sortArray(nums);
        // insert(nums, temp);
        // return nums;
    }
};