class UnionFind {
public:
    vector<int> parent;
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // 路徑壓縮
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) parent[rootX] = rootY;
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        UnionFind uf(n);

        // 1. 建立連通關係
        for (auto& swap : allowedSwaps) {
            uf.unite(swap[0], swap[1]);
        }

        // 2. 將同一集團的索引收集在一起
        // root -> {source_value_counts}
        unordered_map<int, unordered_map<int, int>> groups;
        for (int i = 0; i < n; i++) {
            int root = uf.find(i);
            groups[root][source[i]]++;
        }

        // 3. 計算無法匹配的數量
        int hammingDistance = 0;
        for (int i = 0; i < n; i++) {
            int root = uf.find(i);
            int targetVal = target[i];
            
            // 檢查該位置所屬集團的池子裡，有沒有 target 需要的數字
            if (groups[root][targetVal] > 0) {
                groups[root][targetVal]--; // 匹配成功，消耗一個數字
            } else {
                hammingDistance++; // 沒得換，貢獻一距離
            }
        }

        return hammingDistance;
    }
};