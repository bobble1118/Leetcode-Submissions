class Solution {
private:
    int tree[200020]; // 4 * MX 的線段樹空間

    // 線段樹單點更新：將位置 idx 的值更新為 val
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    // 線段樹區間查詢：查詢 [l, r] 區間內的最大值
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        
        int mid = start + (end - start) / 2;
        return max(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        // 動態決定線段樹邊界，多預留一格空間防越界
        int MX = max_x + 2; 
        memset(tree, 0, sizeof(tree));

        // 儲存所有障礙物，預先放入起點 0 與終點邊界 MX
        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(MX);

        // 初始狀態下，唯一的一格大空格在位置 MX，長度為 MX
        update(1, 0, MX, MX, MX);

        vector<bool> results;

        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int x = q[1];
                auto it = obstacles.upper_bound(x);
                int next_obs = *it;
                int prev_obs = *prev(it);

                // 插入新障礙物
                obstacles.insert(x);

                // 更新線段樹：原本的舊大空格被打破
                // 新空格 A 終點在 x，長度為 x - prev_obs
                update(1, 0, MX, x, x - prev_obs);
                // 新空格 B 終點在 next_obs，長度更新為 next_obs - x
                update(1, 0, MX, next_obs, next_obs - x);

            } else {
                int x = q[1];
                int sz = q[2];

                // 尋找在 x 之前（或剛好在 x 上）的最後一個障礙物
                auto it = obstacles.upper_bound(x);
                int prev_obs = *prev(it);

                // 最大的合法空格有兩種可能：
                // 1. 完全落在 [0, prev_obs] 之間的最長連續空格
                int max_gap = query(1, 0, MX, 0, prev_obs);
                // 2. 落在最後一個障礙物到查詢點 x 之間的殘餘空格
                max_gap = max(max_gap, x - prev_obs);

                // 判斷最大連續空格是否大於等於木塊大小
                results.push_back(max_gap >= sz);
            }
        }

        return results;
    }
};