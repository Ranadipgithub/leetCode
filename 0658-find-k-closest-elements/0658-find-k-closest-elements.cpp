class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int i = 0;i<n;i++){
            pq.push({abs(arr[i] - x), arr[i]});
        }
        vector<int> res;
        for(int i = 0;i<k;i++){
            int el = pq.top().second;
            pq.pop();
            res.push_back(el);
        }
        sort(res.begin(), res.end());
        return res;
    }
};