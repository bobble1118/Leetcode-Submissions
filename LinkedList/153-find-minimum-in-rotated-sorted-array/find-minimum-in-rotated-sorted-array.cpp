class Solution {
public:
    int findMin(vector<int>& nums) {
        int MIN = nums[0];
        for(auto& num: nums){
            if (MIN > num){
                MIN = num;
            }
            else{
                continue;
            }
        }
        return MIN;
    }
};