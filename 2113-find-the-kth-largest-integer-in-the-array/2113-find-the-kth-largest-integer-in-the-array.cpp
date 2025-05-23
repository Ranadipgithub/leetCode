class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        auto cmp = [](const string &a, const string &b) {
            if (a.size() != b.size()) return a.size() > b.size(); // For min-heap
            return a > b;
        };
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }
        for (int i = k; i < n; i++) {
            if (cmp(nums[i], pq.top())) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
