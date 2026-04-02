class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> st(supplies.begin(), supplies.end());
        int n = recipes.size();
        vector<string> res;
        vector<bool> made(n, false);
        while(true){
            bool added = false;
            for(int i = 0;i<n;i++){
                if(made[i]) continue;
                bool fg = true;
                for(int j = 0;j<ingredients[i].size();j++){
                    if(!st.count(ingredients[i][j])){
                        fg = false;
                        break;
                    }
                }
                if(fg){
                    st.insert(recipes[i]);
                    res.push_back(recipes[i]);
                    made[i] = true;
                    added = true;
                }
            }
            if(!added) break;
        }
        
        return res;
    }
};