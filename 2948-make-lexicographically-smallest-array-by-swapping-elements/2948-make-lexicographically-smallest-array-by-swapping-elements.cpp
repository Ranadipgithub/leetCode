class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // 1 5 3 9 8
        // 0 1 2 3 4
        // (1, 0) (3, 2) (5, 1) (8, 4) (9, 3)
        // 
        int n = nums.size();
        vector<pair<int, int>> temp(n);
        for(int i = 0;i<n;i++){
            temp[i] = {nums[i], i};
        }
        sort(temp.begin(), temp.end());
        int i = 0;
        vector<int> res(n);
        while(i < n){
            int j = i + 1;
            while(j < n && (temp[j].first -temp[j-1].first) <= limit) j++;
            vector<int> indices;
            indices.reserve(j-i);
            for(int k = i;k<j;k++){
                indices.push_back(temp[k].second);
            }
            sort(indices.begin(), indices.end());
            for(int k = 0;k<indices.size();k++){
                res[indices[k]] = temp[i+k].first;
            }
            i = j;
        }
        return res;
    }
};