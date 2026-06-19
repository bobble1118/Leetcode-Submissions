class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int res = 0;
        int last = 0, next = 0;
        for (int i = 0; i < n; i++){
            // Ai+1 = gain(Ai+1 - Ai) + last(Ai)
            next = gain[i] + last;
            res = max(res, next);
            last = next;
        }
        return res;
    }
};