class Fancy {
public:
    vector<int> nums;
    long long add , mult;
    const int mod = 1e9+7;
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, mod - 2);
    }
    // 2 add = 0, mult = 1;
    // 2 add = 3, mult = 1;
    // 2 7 add = 3, mult = 1;
    // 2 7 => (2+3)*2 (7+3)*2 add = add*Currmult = 6 mult = 2 
    // 2 7 => ((2+3)*2)+3 ((7+3)*2)+3 add = 9 mult = 2 
    // 2 7 => (((2+3)*2)+3)*2 (((7+3)*2)+3)*2 add = 18 mult = 4 
    Fancy() {
        add = 0;
        mult = 1;
    }
    
    void append(int val) {
        long long x = (val - add + mod) % mod;
        x = (x * modInverse(mult)) % mod;
        nums.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc)%mod;
    }
    
    void multAll(int m) {
        add = (add*m)%mod;
        mult = (mult*m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx >= nums.size()) return -1;
        return (nums[idx]*mult + add)%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */