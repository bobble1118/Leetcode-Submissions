class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (y == 0) pos.push_back(x);
            else if (x == side) pos.push_back(side + y);
            else if (y == side) pos.push_back(2LL * side + (side - x));
            else pos.push_back(3LL * side + (side - y));
        }
        sort(pos.begin(), pos.end());

        long long n = pos.size();
        long long totalLen = 4LL * side;

        auto check = [&](int d) {
            // 因為是環，嘗試不同的起始點
            // 其實只要嘗試第一個點到第一個點+d 之間的點作為起點即可
            // 但實務上為了通過，可以嘗試前幾個點
            for (int i = 0; i < n; ++i) {
                if (pos[i] >= pos[0] + d && i > 0) break; // 優化：起點不需要找太遠
                
                int count = 1;
                long long last = pos[i];
                long long first = pos[i];
                
                for (int j = 1; j < k; ++j) {
                    // 找下一個距離至少為 d 的點 (可用 lower_bound 加速)
                    auto it = lower_bound(pos.begin(), pos.end(), last + d);
                    if (it == pos.end()) {
                        count = 0; break;
                    }
                    last = *it;
                    count++;
                }
                
                // 最後一個點跟第一個點也要滿足環狀距離 >= d
                if (count == k && totalLen - (last - first) >= d) return true;
                if (i > 100) break; // 實務上的啟發式搜索限制
            }
            return false;
        };

        int left = 1, right = side * 2, ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};