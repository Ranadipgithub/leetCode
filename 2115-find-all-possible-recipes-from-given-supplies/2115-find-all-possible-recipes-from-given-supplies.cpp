class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> indegree;
        for(int i = 0;i<recipes.size();i++){
            for(int j = 0;j<ingredients[i].size();j++){
                adj[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        // yeast => bread
        // flour => bread;
        // bread => sw
        // meat => sw
        queue <string > q;
        for(int i = 0;i<supplies.size();i++){
            q.push(supplies[i]);
        }

        vector<string> res;
        while(!q.empty()){
            string u = q.front();
            q.pop();

            for(string &v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                    res.push_back(v);
                }
            }
        }
        return res;
    }
};