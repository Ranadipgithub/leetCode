class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        int i = 0, j = 0;

        while(j < n) {
            pq.push({nums[j], j});

            if (j - i + 1 < k) {
                j++;
            }
            else if (j - i + 1 == k) {
                while (!pq.empty() && pq.top().second < i) {
                    pq.pop();
                }

                res.push_back(pq.top().first);

                i++;
                j++;
            }
        }

        return res;
    }
};
