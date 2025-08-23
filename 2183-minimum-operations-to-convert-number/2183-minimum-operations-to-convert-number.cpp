class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        queue<int> q;
        q.push(start);
        unordered_set<int> visited; 
        visited.insert(start);

        int ops = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int el = q.front();
                q.pop();

                if (el == goal) return ops;

                for (int i = 0; i < n; i++) {
                    int nextVals[3] = {el + nums[i], el - nums[i], el ^ nums[i]};

                    for (int nxt : nextVals) {
                        if (nxt == goal) return ops + 1;
                        if (nxt >= 0 && nxt <= 1000 && !visited.count(nxt)) {
                            visited.insert(nxt);
                            q.push(nxt);
                        }
                    }
                }
            }
            ops++;
        }
        return -1;
    }
};