class Solution {
public:
    void solve(long long i, int n, priority_queue<long long, vector<long long>, greater<long long>> &pq, unordered_set<long long> &visited, long long &ans) {
        if (!visited.count(i)) {
            if (n == 1) { 
                ans = i;
                return; 
            }
            visited.insert(i);
            pq.push(i * 2);
            pq.push(i * 3);
            pq.push(i * 5);

            long long mini = pq.top();
            pq.pop();
            
            solve(mini, n - 1, pq, visited, ans);
        } else {
            long long mini = pq.top();
            pq.pop();
            solve(mini, n, pq, visited, ans);
        }
    }

    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> visited;
        long long ans = 1;
        solve(1, n, pq, visited, ans); 
        return (int)ans;
    }
};