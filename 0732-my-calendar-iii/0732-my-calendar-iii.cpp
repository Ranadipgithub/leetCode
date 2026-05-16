class MyCalendarThree {
public:
    map<int, int> mpp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mpp[startTime] += 1;
        mpp[endTime] -=1;
        int curr =0, maxi = 0;
        for(auto &it: mpp){
            curr += it.second;
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */