class Solution {
public:
    bool isAnagram(string &s1, string &s2){
        unordered_map<char, int> mpp;
        if(s1.size() != s2.size()) return false;
        for(int i = 0;i<s1.size();i++){
            mpp[s1[i]]++;
        }
        for(int i = 0;i<s2.size();i++){
            if(mpp.count(s2[i])){
                mpp[s2[i]]--;
                if(mpp[s2[i]] == 0) mpp.erase(s2[i]);
            }
        }
        return mpp.size() == 0;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> res;
        res.push_back(words[0]);
        for(int i = 1;i<n;i++){
            if(!isAnagram(words[i], res.back())){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};