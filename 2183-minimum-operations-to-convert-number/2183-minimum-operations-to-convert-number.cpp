class Solution {
public: 
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        int x = start;
        queue<int> q;
        q.push(x);
        int ops = 0;
        set<int> visited;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int el = q.front();
                q.pop();

                if(el == goal) return ops;
                if(el < 0 || el > 1000 || visited.count(el)) continue;
                visited.insert(el);

                for(int i = 0;i<n;i++){
                    int add = el + nums[i];
                    int sub = el - nums[i];
                    int xorop = el ^ nums[i];

                    if(add <= 1000) q.push(add);
                    q.push(sub);
                    if(xorop >= 0 && xorop <= 1000) q.push(xorop);
                }
            }
            ops++;
        }
        return -1;
    }
};