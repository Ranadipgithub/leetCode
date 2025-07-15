class Solution {
public:
    vector<int> findLeftMax(vector<int> &height){
        int n = height.size();
        vector<int> res(n);
        res[0] = height[0];
        for(int i = 1;i<n;i++){
            res[i] = max(res[i-1], height[i]);
        }
        return res;
    }

    vector<int> findRightMax(vector<int> &height){
        int n = height.size();
        vector<int> res(n);
        res[n-1] = height[n-1];
        for(int i = n-2;i>=0;i--){
            res[i] = max(res[i+1], height[i]);
        }
        return res;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax = findLeftMax(height);
        vector<int> rightMax = findRightMax(height);

        int amt = 0;
        for(int i = 0;i<n;i++){
            int ht = min(leftMax[i], rightMax[i]);
            amt += (ht-height[i]);
        }
        return amt;
    }
};