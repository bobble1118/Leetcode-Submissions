class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end(), greater<int>());

        int res = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            if (count < 2){
                res += cost[i];
                count++;
            }else{
                count = 0;
                continue;
            }
        }
        return res;
    }
};