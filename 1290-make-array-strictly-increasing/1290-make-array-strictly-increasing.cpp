class Solution {
public:
    unordered_map<string, int>mpp;
    int solve(vector<int>& arr1, vector<int>& arr2, int i, int prevVal) {
        if (i == arr1.size()) {
            return 0;
        }
        string key = to_string(i) + "_" + to_string(prevVal);
        if(mpp.count(key)) return mpp[key];
        int ops = INT_MAX;
        // Option 1: keep arr1[i] if it's valid
        if (arr1[i] > prevVal) {
            ops = solve(arr1, arr2, i + 1, arr1[i]);
        }
        // Option 2: replace arr1[i] with next greater in arr2
        auto it = upper_bound(arr2.begin(), arr2.end(), prevVal);
        if (it != arr2.end()) {
            int temp = solve(arr1, arr2, i + 1, *it);
            if (temp != INT_MAX) {
                int replaceOps = 1 + temp;
                ops = min(ops, replaceOps);
            }
        }

        return mpp[key] = ops;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int ops = solve(arr1, arr2, 0, INT_MIN);
        return (ops >= 2e9 ? -1 : ops);
    }
};
