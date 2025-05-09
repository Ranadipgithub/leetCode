class Solution {
public:
    int nextGreaterElement(int num) {
        string s = to_string(num);
        int n = s.length();
        int pivotIdx = -1;
        for(int i = n-2;i>=0;i--){
            if(s[i]<s[i+1]){
                pivotIdx = i;
                break;
            }
        }
        if(pivotIdx == -1){
            return -1;
        }
        for(int i = n-1;i>pivotIdx;i--){
            if(s[i] > s[pivotIdx]){
                swap(s[i], s[pivotIdx]);
                break;
            }
        }
        reverse(s.begin()+pivotIdx+1, s.end());
        long long res = stoll(s);
        return (res > INT_MAX) ? -1 : (int)res;
    }
};