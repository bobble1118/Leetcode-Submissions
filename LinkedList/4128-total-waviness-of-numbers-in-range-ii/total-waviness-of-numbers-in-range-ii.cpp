class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        using ll = long long;
        
        auto solve = [&](ll num) -> ll {
            if (num < 100) return 0;
            string s = to_string(num);
            int n = s.size();

            ll memo_cnt[16][11][11];
            ll memo_sum[16][11][11];
            memset(memo_cnt, -1, sizeof(memo_cnt));
            memset(memo_sum, -1, sizeof(memo_sum));

            // 使用 10 代表該位置尚未填入有效數字 (替代 -1 方便作為陣列索引)
            auto dfs = [&](this auto&& dfs, int pos, int prev, int curr,
                           bool isLimit, bool isLeading) -> pair<ll, ll> {
                if (pos == n) {
                    return {1, 0};
                }
                
                if (!isLimit && !isLeading) {
                    if (memo_cnt[pos][prev][curr] != -1) {
                        return {memo_cnt[pos][prev][curr], memo_sum[pos][prev][curr]};
                    }
                }

                ll cnt = 0, sum = 0;
                int up = isLimit ? s[pos] - '0' : 9;
                
                for (int digit = 0; digit <= up; ++digit) {
                    bool nextLeading = isLeading && (digit == 0);
                    
                    int nextPrev, nextCurr;
                    if (nextLeading) {
                        nextPrev = 10;
                        nextCurr = 10;
                    } else if (isLeading) {
                        // 剛從前導零切換到有效數字的第一個字元
                        nextPrev = 10;
                        nextCurr = digit;
                    } else {
                        // 正常數字滾動
                        nextPrev = curr;
                        nextCurr = digit;
                    }

                    auto [subCnt, subSum] = dfs(pos + 1, nextPrev, nextCurr, isLimit && (digit == up), nextLeading);
                    
                    // 結算當前點的波浪貢獻：必須在「非前導零」且「前兩位皆有效」時
                    if (!isLeading && prev != 10 && curr != 10) {
                        if ((prev < curr && curr > digit) || (prev > curr && curr < digit)) {
                            sum += subCnt;
                        }
                    }

                    cnt += subCnt;
                    sum += subSum;
                }

                if (!isLimit && !isLeading) {
                    memo_cnt[pos][prev][curr] = cnt;
                    memo_sum[pos][prev][curr] = sum;
                }

                return {cnt, sum};
            };

            auto [_, totalSum] = dfs(0, 10, 10, true, true);
            return totalSum;
        };

        return solve(num2) - solve(num1 - 1);
    }
};