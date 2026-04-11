class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            string temp = to_string(nums[i]);
            for(char ch: temp){
                if(ch == digit + '0') cnt++;
            }
        }
        return cnt;
    }
};