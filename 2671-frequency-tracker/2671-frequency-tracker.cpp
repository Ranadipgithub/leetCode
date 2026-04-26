class FrequencyTracker {
public:
    unordered_map<int, int> mpp;
    unordered_map<int, int> fq;
    FrequencyTracker() {
        mpp.clear();
        fq.clear();
    }
    
    void add(int number) {
        if(mpp[number] > 0) fq[mpp[number]]--;
        mpp[number]++;
        fq[mpp[number]]++;
    }
    
    void deleteOne(int number) {
        if(mpp.count(number)){
            fq[mpp[number]]--;
            mpp[number]--;
            if(mpp[number] == 0){
                mpp.erase(number);         
            } else {
                fq[mpp[number]]++;         
            }
        }
    }
    
    bool hasFrequency(int freq) {
        return fq[freq] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */