class Solution {
public:
    long long wonderfulSubstrings(string word) {
        // the substring can contain atmost one character with odd freq
        // we will use bitmasking to track whether the letter occurred odd no
        // of times or even no of times
        // if the no of occurance of a bit is odd, then the xor is also odd
        // we will use this property to build our prefix xor
        // now as the no of characters is 10(a to j) so we need 10 bits, that means
        // total 2^10 = 1024 possibility
        // 1: odd no of occurance, 0: even no of occurance
        // let's say the xor upto a certain point is x, now if we have seen this
        // xor before that means the characters between them is cancelled out,
        // that means they occurred even no of times, so this is for condition one
        // where we are checking the substring with only even characters
        // now we have to check the substring with only 1 odd character
        // a substring which contains only one odd charcter, if we xor that subtring
        // with that character the resulting xorr will be 0
        // therefore we have to iterate from a to j and have to find out the xor of
        // which character with the substring giving the resulting xor as 0
        // the charac which gives the xorr 0 is the character with odd freq
        // 
        int n = word.size();
        int mask = 0;
        // unordered_map<int, long long> mpp;
        vector<long long> mpp(1024, 0);
        mpp[0] = 1;
        long long cnt = 0;
        for(int i = 0;i<n;i++){
            int idx = word[i] - 'a';
            mask = mask ^ (1 << idx);
            cnt += mpp[mask];
            for(int i = 0;i<10;i++){
                int temp = mask ^ (1<<i);
                cnt += mpp[temp];
            }
            mpp[mask]++;
        }
        return cnt;
    }
};