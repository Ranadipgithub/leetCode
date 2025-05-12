class Solution {
public:
    bool isPoss(int i, vector<int>& digits, int n){
        string s = to_string(i);
        map<int, int> freq;

        for (int d : digits) {
            freq[d]++;
        }

        for (char c : s) {
            int digit = c - '0';
            if (freq[digit] == 0) return false;
            freq[digit]--;
        }

        return true;
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> res;

        for (int i = 100; i <= 999; i++) {
            if (i % 2 == 0 && isPoss(i, digits, n)) {
                res.push_back(i);
            }
        }

        return res;
    }
};
