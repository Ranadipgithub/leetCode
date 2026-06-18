class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hrs = (double)hour*30 + (double)minutes*0.5;
        double mins = (double)minutes * 6;
        double ans = min(abs(hrs-mins), 360 - abs(hrs-mins));
        return ans;
    }
};