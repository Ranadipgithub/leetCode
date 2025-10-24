class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<int> nums = {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666};
        vector<int> res;
        for(int num: nums){
            string s = to_string(num);
            while(next_permutation(s.begin(), s.end())){
                res.push_back(stoi(s));
            }
        }
        for(int num: nums){
            res.push_back(num);
        }
        sort(res.begin(), res.end());
        for(int num: res) cout << num << " ";
        auto it = upper_bound(res.begin(), res.end(), n);
        if (it != res.end()) return *it;
        return 1224444;
    }
};