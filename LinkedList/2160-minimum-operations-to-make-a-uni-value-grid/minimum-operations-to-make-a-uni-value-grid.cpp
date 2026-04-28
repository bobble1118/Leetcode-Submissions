class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> r;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                r.push_back(grid[i][j]);
            }
        }
        
        int check = r[0] % x;
        for (const auto& i: r){
            if (i%x != check) return -1;
        }

        sort(r.begin(), r.end());
        int median = r[r.size()/2];

        int res = 0;
        for (const auto& i: r){
            res += abs(i-median)/x;
        }
        return res;
    }
};