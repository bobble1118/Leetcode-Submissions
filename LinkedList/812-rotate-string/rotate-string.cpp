class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if (n != m) return false;
        int flag = 0;

        for (int i = 0; i < n; i++){
            if (s[i] != goal[0]) continue;
            for(int j = 0; j < n; j++){
                if (s[(i+j) % n] != goal[j]) break;
                else if(j == n-1){
                    flag = 1;
                    break;
                }
            }
        }
        return flag;
    }
};