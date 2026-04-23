class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        unordered_map<int, vector<int>> valToIndices;

        // 1. 將相同數值的索引歸類
        for (int i = 0; i < n; i++) {
            valToIndices[nums[i]].push_back(i);
        }

        // 2. 針對每一組相同的數字進行前綴和計算
        for (auto& entry : valToIndices) {
            const vector<int>& p = entry.second;
            int k = p.size();
            if (k <= 1) continue;

            // 計算該組索引的總和，作為後綴和的起點
            long long totalSum = 0;
            for (int index : p) totalSum += index;

            long long leftSum = 0;
            for (int i = 0; i < k; i++) {
                long long currentIdx = p[i];
                // 右側所有索引的總和 (不含自己)
                long long rightSum = totalSum - leftSum - currentIdx;

                // 左側距離總和：(左邊個數 * 自己) - 左邊總和
                long long leftPart = (long long)i * currentIdx - leftSum;
                // 右側距離總和：右邊總和 - (右邊個數 * 自己)
                long long rightPart = rightSum - (long long)(k - 1 - i) * currentIdx;

                arr[p[i]] = leftPart + rightPart;

                // 更新左側總和，供下一個索引使用
                leftSum += currentIdx;
            }
        }

        return arr;
    }
};