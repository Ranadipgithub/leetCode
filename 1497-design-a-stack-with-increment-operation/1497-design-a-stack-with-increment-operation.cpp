class CustomStack {
public:
    vector<int> arr;
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (arr.size() < maxSize) {
            arr.push_back(x);
        }
    }
    
    int pop() {
        if (arr.empty()) return -1;
        int val = arr.back();
        arr.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min((int)arr.size(), k); i++) {
            arr[i] += val;
        }
    }
};


/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */