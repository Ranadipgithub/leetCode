class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = accumulate(apple.begin(), apple.end(), 0);
        int cnt = 0;
        sort(capacity.begin(), capacity.end(), greater<int>());
        for(int i = 0;i<capacity.size();i++){
            total -= capacity[i];
            cnt++;
            if(total <= 0) return cnt;
        }
        return -1;
    }
};