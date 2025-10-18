class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> arr;
        for(int i = 0;i<n;i++){
            arr.push_back(to_string(nums[i]));
        }
        sort(arr.begin(), arr.end(), [](string &s1, string &s2){
            return s1 + s2 > s2 + s1;
        });
        string res;
        for(int i = 0;i<n;i++){
            res += arr[i];
        }
        int idx = -1;
        for(int i = 0;i<n;i++){
            if(res[i] == '0'){
                idx = i;
            }
            else break;
        }
        cout << idx;
        return idx != -1? res.substr(idx): res;
    }
};