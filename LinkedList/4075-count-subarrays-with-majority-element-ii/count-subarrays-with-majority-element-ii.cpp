class Solution {
private:
    vector<int> tree;
    int tree_size;

    // 樹狀陣列標準單點更新：在位置 idx 加上 val
    void update(int idx, int val) {
        for (; idx <= tree_size; idx += idx & -idx) {
            tree[idx] += val;
        }
    }

    // 樹狀陣列標準前綴和查詢：查詢 [1, idx] 的總和
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }

public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // 前綴和範圍是 [-n, n]，平移後最大索引會達到 2 * n + 2
        tree_size = 2 * n + 2;
        tree.assign(tree_size + 1, 0);

        // 偏移量：用來把負數與 0 映射到正整數區間
        int offset = n + 1;
        
        long long total_subarrays = 0;
        int current_p_sum = 0;

        // 初始狀態：在還沒處理任何數字前，前綴和為 0 的狀態已經出現過 1 次
        update(0 + offset, 1);

        for (int x : nums) {
            // 1. 轉換為 +1 / -1 流
            current_p_sum += (x == target) ? 1 : -1;

            // 2. 核心查詢：我們要找歷史前綴和 < current_p_sum 的個數
            // 等價於查詢樹狀陣列中從 1 到 (current_p_sum - 1 + offset) 的累積次數
            total_subarrays += query(current_p_sum - 1 + offset);

            // 3. 登記歷史：將當前的前綴和狀態加入樹狀陣列
            update(current_p_sum + offset, 1);
        }

        return total_subarrays;
    }
};