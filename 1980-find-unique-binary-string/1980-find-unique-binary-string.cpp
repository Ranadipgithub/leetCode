class Solution {
public:
    unordered_set<string> st;
    string solve(string &temp, int idx){
        if(idx == temp.size()){
            if(!st.count(temp)) return temp;
            return "";
        }

        string res = solve(temp, idx+1);
        if(res != "") return res;

        temp[idx] = '1';
        res = solve(temp, idx+1);
        if(res != "") return res;
        temp[idx] = '0';
        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        for(auto &it: nums) st.insert(it);

        string temp;
        temp.resize(n, '0');

        return solve(temp, 0);
    }
};