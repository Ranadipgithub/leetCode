class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int n = s.size();
        int cols = n/rows;
        string res = "";
        for(int j = 0;j<cols;j++){
            int row = 0, col = j;
            while(row < rows && col < cols){
                int idx = (row*cols) + col;
                res += s[idx];
                row++;
                col++;
            }
        }
        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }
        return res;
    }
};