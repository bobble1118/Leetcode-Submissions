class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int m = nums.size();
        vector<int> ans(m, 0);
        vector<int> premax(m, -INT_MAX);
        vector<int> surmin(m, INT_MAX);

        premax[0] = nums[0];
        for (int i = 1; i < m; i++){
            premax[i] = max(nums[i], premax[i-1]);
        }

        surmin[m-1] = nums[m-1];
        for (int i = m-2; i >= 0; i--){
            surmin[i] = min(nums[i], surmin[i+1]);
        }


        ans[m-1] = premax[m-1];
        for (int i = m-2; i >= 0; i--){
            if (premax[i] <= surmin[i+1]){
                ans[i] = premax[i];
            }
            else{
                ans[i] = ans[i+1];
            }
        }

        return ans;
    }
};
