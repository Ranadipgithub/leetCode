class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        unordered_map<int, list<int>> grpEl;
        int grp = 0;
        grpEl[grp].push_back(temp[0]);
        unordered_map<int, int> grpNo;
        grpNo[nums[0]] = grp;
        for(int i = 1;i<n;i++){
            if(abs(temp[i] - temp[i-1]) <= limit){
                grpEl[grp].push_back(temp[i]);
                grpNo[temp[i]] = grp;
            } else {
                grp++;
                grpEl[grp].push_back(temp[i]);
                grpNo[temp[i]] = grp;
            }
        }
        vector<int> res(n);
        for(int i = 0;i<n;i++){
            int grp = grpNo[nums[i]];
            res[i] = *(grpEl[grp].begin());
            grpEl[grp].pop_front();
        }
        return res;
    }
};