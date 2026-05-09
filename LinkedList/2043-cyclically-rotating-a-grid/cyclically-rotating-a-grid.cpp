class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int numLayers = min(m, n) / 2;

        for (int layer = 0; layer < numLayers; layer++) {
            // 1. 提取第 layer 層的所有元素
            vector<int> elements;
            
            // Top: left -> right
            for (int j = layer; j < n - 1 - layer; j++) elements.push_back(grid[layer][j]);
            // Right: top -> bottom
            for (int i = layer; i < m - 1 - layer; i++) elements.push_back(grid[i][n - 1 - layer]);
            // Bottom: right -> left
            for (int j = n - 1 - layer; j > layer; j--) elements.push_back(grid[m - 1 - layer][j]);
            // Left: bottom -> top
            for (int i = m - 1 - layer; i > layer; i--) elements.push_back(grid[i][layer]);

            // 2. 計算實際旋轉位移
            int len = elements.size();
            int netRotation = k % len;
            
            // 3. 將旋轉後的元素放回原位
            // 我們可以使用一個指標 p 來追蹤 elements 中的位置
            int p = netRotation; 
            auto getNext = [&]() {
                int val = elements[p];
                p = (p + 1) % len;
                return val;
            };

            for (int j = layer; j < n - 1 - layer; j++) grid[layer][j] = getNext();
            for (int i = layer; i < m - 1 - layer; i++) grid[i][n - 1 - layer] = getNext();
            for (int j = n - 1 - layer; j > layer; j--) grid[m - 1 - layer][j] = getNext();
            for (int i = m - 1 - layer; i > layer; i--) grid[i][layer] = getNext();
        }

        return grid;
    }
};