class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k, int i_, int j_) {
        int n = nums.size();
        map<int, int> mpp;
        for(int i = i_;i<j_;i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it: mpp){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()){
            int el = pq.top().second;
            res.push_back(el);
            pq.pop();
        }
        return res;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        map<int, int> mpp;
        vector<int> res;
        int i = 0;

        for (int j = 0; j < n; j++) {
            mpp[nums[j]]++;

            if (j - i + 1 > k) {
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }
                i++;
            }

            if (j - i + 1 == k) {
                vector<int> temp = topKFrequent(nums, x, i, j + 1);
                int sum = 0;
                for (int el : temp) {
                    if (mpp.count(el)) {
                        sum += el * mpp.at(el);
                    }
                }
                res.push_back(sum);
            }
        }
        return res;
    }
};