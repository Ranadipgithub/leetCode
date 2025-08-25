class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<int>> adj;
        unordered_set<string> st(supplies.begin(), supplies.end());
        int n = recipes.size();
        vector<int> indegree(n, 0);
        for(int i = 0;i<n;i++){
            for(string s: ingredients[i]){
                if(!st.count(s)){
                    adj[s].push_back(i);
                    indegree[i]++;
                }
            }
        }
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<string> res;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            string recipe = recipes[i];
            res.push_back(recipe);

            for(int &idx: adj[recipe]){
                indegree[idx]--;
                if(indegree[idx] == 0){
                    q.push(idx);
                }
            }
        }
        return res;
    }
};