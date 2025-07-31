class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> ans, prevOr;
        for(auto x : arr){
            unordered_set<int> curOr; 
            curOr.insert(x);
            for(auto y : prevOr) curOr.insert(y|x);
            ans.insert(curOr.begin(),curOr.end());
            prevOr = curOr;
        }
        return ans.size();
    }
};