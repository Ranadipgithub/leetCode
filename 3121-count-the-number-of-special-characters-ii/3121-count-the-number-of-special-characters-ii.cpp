class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        unordered_map<char, int> mpp;
        unordered_map<char, vector<int>> upper, lower;
        for(int i = 0;i<n;i++){
            if(isupper(word[i])) upper[tolower(word[i])].push_back(i);
            else lower[word[i]].push_back(i);
        }
        int cnt = 0;
        vector<int> res(26, 0);
        unordered_set<char> visited;
        for(int i = 0;i<n;i++){
            if(isupper(word[i]) && !visited.count(word[i])){
                if(mpp.count(tolower(word[i]))){
                    vector<int> temp = lower[tolower(word[i])];
                    auto it = upper_bound(temp.begin(), temp.end(), i);
                    if(it == temp.end()) res[word[i]-'A'] = 1;
                }
                visited.insert(word[i]);
            } else mpp[word[i]]++;
        }
        return accumulate(res.begin(), res.end(), 0);
    }
};