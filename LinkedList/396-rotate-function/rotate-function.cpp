class Solution {

public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        long long val = 0;

        long long sum = 0;
        for (int i = 0; i < n; i++){
            sum += nums[i];
            val += (long long)i * nums[i];
        }
        
        long long res = val;
        for (int k = 1; k < n; k++){
            val = val + sum - n * nums[n-k];
            res = max(val, res);
        }
        return (int)res;
    }
};