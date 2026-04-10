class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }

        int mini = INT_MAX;
        for(auto it: mpp){
            vector<int> temp = it.second;
            if(temp.size() < 3) continue;
            for(int i = 2;i<temp.size();i++){
                mini = min(mini, 2*(temp[i] - temp[i-2]));
            }
        }
        return mini == INT_MAX? -1: mini;
    }
};