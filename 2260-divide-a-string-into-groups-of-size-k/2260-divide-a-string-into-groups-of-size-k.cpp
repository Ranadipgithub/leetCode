class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        string temp = "";
        vector<string> res;
        for(int i = 0;i<n;i++){
            temp += s[i];
            if((i+1)%k == 0){
                res.push_back(temp);
                temp.clear();
            }
            
        }
        if(n % k == 0) return res;
        while(temp.size() != k){
            temp += fill;
        }
        res.push_back(temp);
        return res;
    }
};