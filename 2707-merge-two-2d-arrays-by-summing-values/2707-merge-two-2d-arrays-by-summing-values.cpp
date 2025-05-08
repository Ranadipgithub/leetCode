class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> res;

        int i = 0, j = 0;

        while(i<n && j<m){
            if(nums1[i][0] < nums2[j][0]){
                res.push_back(nums1[i]);
                i++;
            } else if(nums1[i][0] > nums2[j][0]){
                res.push_back(nums2[j]);
                j++;
            } else{
                res.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
        }

        while(i < n){
            res.push_back(nums1[i]);
            i++;
        }

        while(j < m){
            res.push_back(nums2[j]);
            j++;
        }

        return res;

        // map<int, int> mpp;
        // vector<vector<int>> result;

        // for(int i = 0;i<n;i++){
        //     int id = nums1[i][0];
        //     int val = nums1[i][1];

        //     mpp[id] += val;
        // }

        // for(int i = 0;i<m;i++){
        //     int id = nums2[i][0];
        //     int val = nums2[i][1];

        //     mpp[id] += val;
        // }

        // for(auto &it: mpp){
        //     int key = it.first;
        //     int val = it.second;

        //     result.push_back({key, val});
        // }

        // // sort(begin(result), end(result));
        // return result;
    }
};