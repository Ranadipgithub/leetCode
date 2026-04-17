class Solution {
public:
    int rev(int n){
        int ans = 0;
        while(n>0){
            ans = ans*10 + n%10;
            n /= 10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        unordered_map<int, vector<int>> mpp;
        for(int i = 0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }

        for(int i = 0;i<n;i++){
            int reverse = rev(nums[i]);
            cout << reverse << " ";
            if(mpp.count(reverse)){
                auto it = upper_bound(mpp[reverse].begin(), mpp[reverse].end(), i);
                // int idx = it-mpp[reverse].begin();
                // if(i < idx){
                //     mini = min(mini, abs(mpp[reverse][mpp[reverse].size()-1]-idx));
                // }
                if(it != mpp[reverse].end()){
                    mini = min(mini, *it-i);
                }
            }
        }
        return mini == INT_MAX? -1: mini;
    }
};