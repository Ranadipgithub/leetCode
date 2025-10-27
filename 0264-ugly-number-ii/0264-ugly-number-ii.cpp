class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1);
        int i2=1, i3=1, i5=1;
        arr[1] = 1;
        for(int i = 2;i<=n;i++){
            int i2_ = 2*arr[i2];
            int i3_ = 3*arr[i3];
            int i5_ = 5*arr[i5];
            int mini = min({i2_, i3_, i5_});
            arr[i] = mini;
            if(i2_ == mini) i2++;
            if(i3_ == mini) i3++;
            if(i5_ == mini) i5++;
        }
        return arr[n];
    }
};