class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0, cnt = 0;
        for(char c : moves) {
            switch(c) {
                case 'U': y++; break;
                case 'D': y--; break;
                case 'L': x--; break;
                case 'R': x++; break;
                default: cnt++;
            }
        }
        return abs(x) + abs(y) + cnt;
    }
};