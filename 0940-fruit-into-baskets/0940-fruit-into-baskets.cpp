class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i = 0, j = 0;
        unordered_map<int, int> mpp;
        int maxLen = 0;
        while(j<n){
            mpp[fruits[j]]++;
             if(mpp.size() <= 2){
                maxLen = max(maxLen, j-i+1);
                j++;
            } else{
                while(mpp.size() != 2){
                    mpp[fruits[i]]--;
                    if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        return maxLen;
    }
};