class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    long long beautifulSubstrings(string s, int k) {
        // i+1 .... j
        // vowels = v[j] - v[i]
        // cons = c[j] - c[i]
        // v[j] - v[i] = c[j] - c[i]
        // v[j] - c[j] = v[i] - c[i]
        // (v[j] - v[i])*(c[j] - c[i]) % k = 0
        // (v[j] - v[i])^2 % k = 0
        // we have to find the smallest int l such that l*l % k is 0
        // now if v[j]-v[i] is a multiple of l then (v[j] - v[i])^2 is guaranteed to be a multiple of k
        // (v[j] - v[i]) % l = 0 => v[j] % l = v[i] % l
        // therefore two conditions are:
        // 1: v[j] - c[j] = v[i] - c[i]
        // 2: v[j] % l = v[i] % l
        
        int n = s.size();
        map<pair<int, int>, int> mpp;
        int l = 1;
        while((l*l)%k != 0) l++;
        mpp[{0, 0}] = 1;
        long long cnt = 0, v = 0, c = 0;
        for(int i = 0;i<n;i++){
            if(isVowel(s[i])) v++;
            else c++;

            pair<int, int> curr = {v-c, v%l};
            cnt += mpp[curr];
            mpp[curr]++;
        }
        return cnt;
    }
};