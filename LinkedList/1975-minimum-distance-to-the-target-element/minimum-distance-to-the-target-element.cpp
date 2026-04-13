class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int min_d = 100000;

        for (int i = 0; i < n; i++){
            if ((start + i) < n && nums[start + i] == target){
                min_d = min(min_d, abs(i));
            }
            if ((start - i) >= 0 && nums[start - i] == target){
                min_d = min(min_d, abs(i));
            }
        }
        return min_d;
    }
};