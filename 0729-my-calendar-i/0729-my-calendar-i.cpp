class MyCalendar {
public:
    map<int, int> mpp;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        mpp[startTime] += 1;
        mpp[endTime] -= 1;
        int curr = 0;
        for(auto it: mpp){
            curr += it.second;
            if(curr >= 2){
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
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */