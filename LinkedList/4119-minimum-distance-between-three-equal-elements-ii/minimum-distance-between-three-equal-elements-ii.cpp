class Solution {
public:
    struct Item {
        int idx, val;
    };

    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return -1;

        vector<Item> dataList(n);
        for (int i = 0; i < n; i++) dataList[i] = {i, nums[i]};

        sort(dataList.begin(), dataList.end(), [](const Item& a, const Item& b) {
            if (a.val != b.val) return a.val < b.val;
            return a.idx < b.idx;
        });

        int min_dist = INT_MAX;
        bool found = false;

        for (int r = 2; r < n; r++) {
            if (dataList[r].val == dataList[r - 1].val && dataList[r].val == dataList[r - 2].val) {
                int current_dist = 2 * (dataList[r].idx - dataList[r - 2].idx);
                min_dist = min(min_dist, current_dist);
                found = true;
            }
        }

        return found ? min_dist : -1;
    }
};