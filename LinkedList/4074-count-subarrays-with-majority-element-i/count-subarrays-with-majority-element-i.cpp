class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        // 統計每個前綴和數值出現的次數
        vector<int> count_map(2 * n + 2, 0);
        int offset = n;
        
        count_map[0 + offset] = 1;
        
        long long ans = 0;
        int p_sum = 0;
        int smaller_gaps = 0; // 核心優化：用來動態維護「目前小於 p_sum 的歷史個數總和」

        for (int x : nums) {
            if (x == target) {
                // p_sum 往右移一格 (+1)
                // 那些原本等於舊 p_sum 的人，現在都變成「小於新 p_sum」的人了！
                smaller_gaps += count_map[p_sum + offset];
                p_sum++;
            } else {
                // p_sum 往左移一格 (-1)
                p_sum--;
                // 那些原本等於新 p_sum 的人，現在不再小於它了，必須扣除
                smaller_gaps -= count_map[p_sum + offset];
            }
            
            ans += smaller_gaps;
            count_map[p_sum + offset]++;
        }
        
        return ans;
    }
};