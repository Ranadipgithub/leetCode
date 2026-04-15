class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int cnt = 0;
        int i = startIndex, j = startIndex;
        int n = words.size();
        while(cnt <= words.size()){
            if(words[i] == target || words[j] == target) return cnt;
            i = (i+1)%n;
            j = (j-1+n)%n;
            cnt++;
        }
        return -1;
    }
};