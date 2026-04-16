class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> valToIndices;

        // 1. 預處理：將相同數值的索引歸類
        for (int i = 0; i < n; i++) {
            valToIndices[nums[i]].push_back(i);
        }

        vector<int> results;
        results.reserve(queries.size()); // 預留空間，效能更佳

        for (int startIdx : queries) {
            int targetVal = nums[startIdx];
            const vector<int>& indices = valToIndices[targetVal];

            // 情況 A：如果該數值只出現一次（只有自己），回傳 -1
            if (indices.size() == 1) {
                results.push_back(-1);
                continue;
            }

            // 情況 B：利用二分搜尋找到自己在 indices 列表中的位置
            auto it = lower_bound(indices.begin(), indices.end(), startIdx);
            int posInList = distance(indices.begin(), it);

            // 取得環狀陣列中的左右鄰居索引
            // 使用取餘數來處理頭尾銜接的狀況
            int leftIdx  = indices[(posInList - 1 + indices.size()) % indices.size()];
            int rightIdx = indices[(posInList + 1) % indices.size()];

            // 計算與左右鄰居的環狀最短距離
            int distToLeft  = calculateCircularDist(startIdx, leftIdx, n);
            int distToRight = calculateCircularDist(startIdx, rightIdx, n);

            results.push_back(min(distToLeft, distToRight));
        }

        return results;
    }

private:
    /**
     * 輔助函式：計算環狀陣列中兩點間的最短距離
     */
    int calculateCircularDist(int i, int j, int n) {
        int linearDist = abs(i - j);
        return min(linearDist, n - linearDist);
    }
};