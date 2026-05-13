class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        // diff[i] 紀錄目標 Sum 為 i 時，總移動次數的變化量
        // 可能的 Sum 範圍是 2 ~ 2*limit
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            
            // 預設每一對都需要移動 2 次
            // 範圍 [2, 2*limit]
            int min_sum = min(a, b) + 1;
            int max_sum = max(a, b) + limit;
            int current_sum = a + b;

            // 1. 對於所有可能的 S，先預設需要 2 次移動
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // 2. 在 [min_sum, max_sum] 區間，只需要 1 次移動
            // 所以相對於 2 次，我們減去 1 (變成 1 次)
            diff[min_sum] -= 1;
            diff[max_sum + 1] += 1;

            // 3. 在剛好等於 current_sum 的位置，只需要 0 次移動
            // 所以相對於 1 次，我們再減去 1 (變成 0 次)
            diff[current_sum] -= 1;
            diff[current_sum + 1] += 1;
        }

        int ans = n; // 最大移動次數不會超過 n
        int current_moves = 0;
        // 透過掃描差分陣列，找出最小的移動次數
        for (int s = 2; s <= 2 * limit; s++) {
            current_moves += diff[s];
            ans = min(ans, current_moves);
        }

        return ans;
    }
};