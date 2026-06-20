class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        restrictions.push_back({n,n-1});

        sort(restrictions.begin(), restrictions.end());
        int m = restrictions.size();

        // left -> right
        for (int i = 1; i < m; i++){
            int dist = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], dist + restrictions[i-1][1]);
        }

        // right -> left
        for (int i = m - 2; i >= 0; i--){
            int dist = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], dist + restrictions[i+1][1]);
        }

        // find max
        int res = 0;
        for (int i = 0; i < m-1; i++){
            int dist = restrictions[i+1][0] - restrictions[i][0];
            res = max(res, (restrictions[i][1]+restrictions[i+1][1]+dist)/2);
        }
        return res;
    }
};