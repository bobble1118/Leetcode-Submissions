class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min_ang = minutes * 6;
        double hour_ang = ((hour % 12) + (double)minutes / 60 ) * 30;
        double res = abs(min_ang - hour_ang);
        return (res > 180) ? 360 - res : res;
    }
};