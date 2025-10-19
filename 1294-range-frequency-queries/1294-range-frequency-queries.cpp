class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mpp;
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if(!mpp.count(value)) return 0;
        vector<int> &temp = mpp[value];
        auto it = lower_bound(temp.begin(), temp.end(), left);
        auto it1 = upper_bound(temp.begin(), temp.end(), right);
        return it1-it;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */