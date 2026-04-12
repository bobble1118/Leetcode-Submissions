class Solution {
    // 輔助函式：計算兩個字母之間的曼哈頓距離
    int getDist(int a, int b) {
        if (a == 26 || b == 26) return 0; // 26 代表手指還沒放上去（初始狀態）
        int r1 = a / 6, c1 = a % 6;
        int r2 = b / 6, c2 = b % 6;
        return abs(r1 - r2) + abs(c1 - c2);
    }

public:
    int minimumDistance(string word) {
        int n = word.size();
        // dp[other_pos] 記錄當前按完字後，另一隻手的位置
        // 初始化為極大值
        vector<int> dp(27, 3200); 
        dp[26] = 0; // 初始狀態：另一隻手還沒放在鍵盤上

        for (int i = 0; i < n; i++) {
            vector<int> next_dp(27, 3200);
            int cur = word[i] - 'A';
            int prev = (i == 0) ? 26 : word[i-1] - 'A';

            for (int other = 0; other <= 26; other++) {
                if (dp[other] == 3200) continue;

                // 選項 A：用「剛按過 prev 的那隻手」來按 cur
                // 另一隻手位置不變，仍是 other
                next_dp[other] = min(next_dp[other], dp[other] + getDist(prev, cur));

                // 選項 B：用「停在 other 的那隻手」來按 cur
                // 另一隻手現在停在 prev (剛按完上一個字的那隻手)
                next_dp[prev] = min(next_dp[prev], dp[other] + getDist(other, cur));
            }
            dp = next_dp;
        }

        int res = 3200;
        for (int d : dp) res = min(res, d);
        return res;
    }
};