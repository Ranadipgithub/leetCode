class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> st(supplies.begin(), supplies.end());
        int n = recipes.size();
        vector<string> res;
        vector<int> done(n, 0); 

        while(n--){ 
            for(int i = 0;i<recipes.size();i++){
                if(done[i]) continue;
                bool fg = true;
                for(int j = 0;j<ingredients[i].size();j++){
                    if(!st.count(ingredients[i][j])){
                        fg = false;
                        break;
                    }
                }
                if(fg){
                    res.push_back(recipes[i]);
                    st.insert(recipes[i]);
                    done[i] = 1;
                }
            }
        }
        return res;
    }
};