class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(x);
        visited.insert(x);
        int ops = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int el = q.front();
                q.pop();

                if(el == y) return ops;
                if(el % 11 == 0){
                    int temp = el;
                    temp = temp/11;
                    if(!visited.count(temp)){
                        q.push(temp);
                        visited.insert(temp);
                    }
                } 
                if(el % 5 == 0){
                    int temp = el;
                    temp = temp / 5;
                    if(!visited.count(temp)){
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
                int temp = el;
                if(!visited.count(temp+1)){
                    q.push(temp+1);
                    visited.insert(temp+1);
                }
                if(!visited.count(temp-1)){
                    q.push(temp-1);
                    visited.insert(temp-1);
                }
            }
            ops++;
        }
        return - 1;
    }
};