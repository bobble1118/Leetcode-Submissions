using vll = std::vector<long long>;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if (n == 1) return 0; // 只有一列時無法形成左右鄰居，得分必為 0

        /**
         * dp[i][currH][prevH]: 
         * 處理到第 i 列，當前高度為 currH，且第 i-1 列高度為 prevH 時的最大總分。
         */
        vector<vector<vll>> dp(n, vector<vll>(n + 1, vll(n + 1, 0)));
        
        // 用於優化轉移過程的輔助陣列，紀錄上一列在不同高度限制下的最大值
        vector<vll> prevMax(n + 1, vll(n + 1, 0));
        vector<vll> prevSuffixMax(n + 1, vll(n + 1, 0));
        
        // 1. 預處理每列的前綴和：colSum[c][r] 代表第 c 列前 r 格的數字總和
        vector<vll> colSum(n, vll(n + 1, 0));
        for (int c = 0; c < n; c++) {
            for (int r = 1; r <= n; r++) {
                colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
            }
        }

        // 2. 開始 DP：從第 1 列遍歷到第 n-1 列
        for (int i = 1; i < n; i++) {
            for (int currH = 0; currH <= n; currH++) {
                for (int prevH = 0; prevH <= n; prevH++) {
                    
                    // 情況 A：當前列高度 <= 前一列高度 (下降趨勢)
                    if (currH <= prevH) {
                        // 當前列 i 的 [currH, prevH] 區間是白色的，且左邊 i-1 是黑色的 -> 產生額外分數
                        long long extraScore = colSum[i][prevH] - colSum[i][currH];
                        dp[i][currH][prevH] = std::max(
                            dp[i][currH][prevH],
                            prevSuffixMax[prevH][0] + extraScore
                        );
                    } 
                    // 情況 B：當前列高度 > 前一列高度 (上升趨勢)
                    else {
                        // 前一列 i-1 的 [prevH, currH] 區間是白色的，且右邊 i 是黑色的 -> 產生額外分數
                        long long extraScore = colSum[i - 1][currH] - colSum[i - 1][prevH];
                        dp[i][currH][prevH] = std::max({
                            dp[i][currH][prevH], 
                            prevSuffixMax[prevH][currH], // 延續之前的最大值
                            prevMax[prevH][currH] + extraScore // 加上落差產生的分數
                        });
                    }
                }
            }

            // 3. 預計算下一列需要的優化值 (Prefix/Suffix Max)
            for (int currH = 0; currH <= n; currH++) {
                // prevMax 用於紀錄「考慮懲罰項後」的最大值
                prevMax[currH][0] = dp[i][currH][0];
                for (int prevH = 1; prevH <= n; prevH++) {
                    long long penalty = (prevH > currH) ? (colSum[i][prevH] - colSum[i][currH]) : 0;
                    prevMax[currH][prevH] = std::max(
                        prevMax[currH][prevH - 1],
                        dp[i][currH][prevH] - penalty
                    );
                }

                // prevSuffixMax 用於快速獲取較高位置的最大值
                prevSuffixMax[currH][n] = dp[i][currH][n];
                for (int prevH = n - 1; prevH >= 0; prevH--) {
                    prevSuffixMax[currH][prevH] = std::max(
                        prevSuffixMax[currH][prevH + 1], 
                        dp[i][currH][prevH]
                    );
                }
            }
        }

        // 4. 最終答案：在最後一列的所有可能高度組合中取最大值
        long long ans = 0;
        for (int k = 0; k <= n; k++) {
            // 考慮最後一列全塗黑或全不塗黑的情況
            ans = std::max({ans, dp[n - 1][n][k], dp[n - 1][0][k]});
        }

        return ans;
    }
};