class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        // 1. 將 arr1 中所有數字的所有前綴存入 HashSet
        for (int val : arr1) {
            while (val > 0) {
                prefixes.insert(val);
                val /= 10; // 透過除以 10 逐一拔除尾數，取得前綴
            }
        }

        int max_len = 0;

        // 2. 遍歷 arr2，尋找存在於 HashSet 中的最長前綴
        for (int val : arr2) {
            while (val > 0) {
                // 如果目前的 val 存在於 arr1 的前綴集中
                if (prefixes.count(val)) {
                    // 計算這個正整數前綴的長度（位數）
                    int len = to_string(val).length(); 
                    max_len = max(max_len, len);
                    break; // 💡 關鍵剪枝：因為 val 是由大變小，第一次在 set 中抓到的一定是當前數字的最長前綴！
                }
                val /= 10;
            }
        }

        return max_len;
    }
};