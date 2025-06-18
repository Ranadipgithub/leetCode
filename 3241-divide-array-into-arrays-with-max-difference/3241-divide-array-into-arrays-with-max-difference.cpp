class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int size = 0;
        vector<int> temp;
        for(int i = 0;i<n;i++){
            size++;
            temp.push_back(nums[i]);
            if(size == 3){
                if(temp.back() - temp.front() > k) return {};
                else res.push_back(temp);
                size = 0;
                temp.clear();
            }
        }
        return res;
    }
};