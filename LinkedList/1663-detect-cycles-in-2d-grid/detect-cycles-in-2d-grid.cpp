class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        
        auto hasCycle = [&](auto self, int r, int c, int pr, int pc) -> bool{
            visited[r][c] = true;

            for (int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                // 邊界範圍內
                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                // 值必須一樣
                if (grid[nr][nc] != grid[r][c]) continue;
                // 不能跟上一個一樣
                if (nr == pr && nc == pc) continue;
                // 拜訪過代表找到了
                if (visited[nr][nc]) return true;
                // 遞迴尋找
                if (self(self, nr, nc, r, c)) return true;
            }
            return false;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (hasCycle(hasCycle, i, j, -1, -1)) return true;
                }
            }
        }

        return false;
    }
};