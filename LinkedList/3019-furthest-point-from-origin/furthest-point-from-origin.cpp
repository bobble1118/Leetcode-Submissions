class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int step = 0;
        int l = 0, r = 0, b = 0;
        for (const char& s: moves){
            if (s == 'L'){
                l++;
            }
            else if (s == 'R'){
                r++;
            }
            else{
                b++;
            }
        }
        return (l > r) ? (l-r+b) :(r-l+b);
    }
};