class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());
        if(st.count("0000")) return -1;
        queue<string> q;
        unordered_set<string> visited;
        q.push("0000");
        visited.insert("0000");
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string top = q.front();
                q.pop();

                if(top == target) return cnt;

                for(int i = 0;i<4;i++){
                    char ch = top[i];
                    char next, prev;
                    next = ch == '9'? '0': ch + 1;
                    prev = ch == '0'? '9': ch - 1;

                    string temp = top;
                    temp[i] = next;
                    if(!st.count(temp) && !visited.count(temp)){
                        q.push(temp);
                        visited.insert(temp);
                    } 
                    temp[i] = prev;
                    if(!st.count(temp) && !visited.count(temp)){
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};