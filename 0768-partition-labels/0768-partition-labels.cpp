class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        int idx = 0;
        vector<int> occ(26, 0);
        for(int i = 0;i<n;i++){
            occ[s[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        vector<int> res;
        for(int i = 0;i<n;i++){
            end = max(end, occ[s[i] - 'a']);
            if(i == end){
                res.push_back(end-start+1);
                start = i+1;
                end = i+1;
            }
        }
        return res;
    }
};