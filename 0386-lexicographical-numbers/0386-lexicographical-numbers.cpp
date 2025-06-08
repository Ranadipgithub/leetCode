class Solution {
public:
    void solve(int curr, int n, vector<int>&res){
        if(curr > n) return;
        res.push_back(curr);
        for(int append = 0;append<=9;append++){
            int temp = (curr*10)+append;
            if(temp > n) return;
            solve(temp, n, res);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i = 1;i<=9;i++){
            solve(i, n, res);
        }
        return res;
        // vector<string> v;
        // for (int i = 1; i <= n; i++) {
        //     v.push_back(to_string(i));
        // }
        // sort(v.begin(), v.end());

        // vector<int> res;
        // for (int i = 0; i < n; i++) { 
        //     res.push_back(stoi(v[i]));
        // }
        // return res;
    }
};
