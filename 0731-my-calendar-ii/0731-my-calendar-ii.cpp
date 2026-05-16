class MyCalendarTwo {
public:
    map<int, int> mpp;
    MyCalendarTwo() {
        mpp.clear();
    }
    
    bool book(int startTime, int endTime) {
        mpp[startTime] += 1;
        mpp[endTime] -= 1;
        int curr = 0;
        for(auto it: mpp){
            curr += it.second;
            if(curr >= 3){
                mpp[startTime] -= 1;
                mpp[endTime] += 1;
                if(mpp[startTime] == 0) mpp.erase(startTime);
                if(mpp[endTime] == 0) mpp.erase(endTime);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */