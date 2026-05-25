class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        queue<int> q;
        q.push(0);
        int last = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(u == n-1) return true;

            int start = max(last +1 , u + minJump);
            int end = min(n-1, u + maxJump);
            for(int i = start;i<=end;i++){
                if(s[i] == '1') continue;
                q.push(i);
            }
            last = max(last, end);
        }
        return false;
    }
};