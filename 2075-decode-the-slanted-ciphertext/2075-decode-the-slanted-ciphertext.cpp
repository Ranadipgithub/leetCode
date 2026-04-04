class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int n = s.size();
        int cols = n/rows;
        unordered_map<int, string> mpp;
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(i-j > 0) continue;
                int idx = (i*cols)+j;
                mpp[j-i] += s[idx];
            }
        }
        string res = "";
        for (int i = 0; i < cols; i++) {
            res += mpp[i];
        }
        
        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }
        return res;
    }
};