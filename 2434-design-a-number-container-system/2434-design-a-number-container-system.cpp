class NumberContainers {
public:
    unordered_map<int, int> mpp1;
    unordered_map<int, set<int>> mpp2;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mpp1.count(index)){
            int prevVal = mpp1[index];
            mpp2[prevVal].erase(index);
            if(mpp2[prevVal].empty()){
                mpp2.erase(prevVal);
            } 
        }
        mpp1[index] = number;
        mpp2[number].insert(index);
    }
    
    int find(int number) {
        if(mpp2.count(number)){
            return *mpp2[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */