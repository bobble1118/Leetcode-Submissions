class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        int startVal = grid[0][0];
        int startCost = (startVal > 0) ? 1 : 0;
        
        if (startCost <= k) {
            dp[0][0][startCost] = startVal;
        } else {
            return -1; 
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cellScore = grid[i][j];
                int cellCost = (cellScore > 0) ? 1 : 0;

                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == -1) continue; 

                    // 嘗試往右走
                    if (j + 1 < n) {
                        int nextCost = c + ((grid[i][j + 1] > 0) ? 1 : 0);
                        if (nextCost <= k) {
                            dp[i][j + 1][nextCost] = max(dp[i][j + 1][nextCost], dp[i][j][c] + grid[i][j + 1]);
                        }
                    }

                    // 嘗試往下走
                    if (i + 1 < m) {
                        int nextCost = c + ((grid[i + 1][j] > 0) ? 1 : 0);
                        if (nextCost <= k) {
                            dp[i + 1][j][nextCost] = max(dp[i + 1][j][nextCost], dp[i][j][c] + grid[i + 1][j]);
                        }
                    }
                }
            }
        }

        int maxRes = -1;
        for (int c = 0; c <= k; c++) {
            maxRes = max(maxRes, dp[m - 1][n - 1][c]);
        }

        return maxRes;
    }
};