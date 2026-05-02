class Solution {
public:
    int rotatedDigits(int n) {
        string s = to_string(n);
        int L = s.size();
        
        // dp[i][state]: 長度為 i，狀態為 state 的數量
        // state 0: invalid, state 1: neutral (0,1,8), state 2: good (2,5,6,9)
        long long dp[6][3] = {0};
        dp[0][1] = 1; // 空數字

        for (int i = 0; i < L; i++) {
            for (int st = 1; st <= 2; st++) {
                if (dp[i][st] == 0) continue;
                for (int d = 0; d <= 9; d++) {
                    int next_st = get_state(d, st);
                    if (next_st != 0) {
                        dp[i + 1][next_st] += dp[i][st];
                    }
                }
            }
        }

        int ans = 0;
        int current_st = 1; // 追蹤前面已經填好的位數狀態
        
        for (int i = 0; i < L; i++) {
            int digit = s[i] - '0';
            int remaining = L - 1 - i;

            for (int d = 0; d < digit; d++) {
                int next_st = get_state(d, current_st);
                if (next_st == 1) {
                    // 如果填完後是 neutral，我們要的是包含 diff 的數量 (state 2)
                    ans += dp[remaining][2];
                } else if (next_st == 2) {
                    // 如果填完後已經是 good，後面填 neutral 或 good 都可以
                    ans += dp[remaining][1] + dp[remaining][2];
                }
            }
            
            // 更新目前前綴的狀態
            current_st = get_state(digit, current_st);
            if (current_st == 0) break; // 如果前綴已經變無效，後面不用看了
            
            // 如果剛好檢查到 N 本身
            if (i == L - 1 && current_st == 2) ans++;
        }

        return ans;
    }

private:
    int get_state(int d, int current_st) {
        if (d == 3 || d == 4 || d == 7) return 0;
        if (current_st == 2) return 2; // 已經是 good，保持 good
        if (d == 2 || d == 5 || d == 6 || d == 9) return 2; // 變成 good
        return 1; // 保持 neutral
    }
};
