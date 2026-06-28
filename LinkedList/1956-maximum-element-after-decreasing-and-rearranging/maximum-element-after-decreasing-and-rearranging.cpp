class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        if (arr.size() == 1) return 1;
        sort(arr.begin(), arr.end());

        int curr = 0;
        for (const auto& val: arr){
            if (val == curr){
                continue;
            }
            else if (val > curr){
                curr++;
            }
        }
        return curr;
    }
};