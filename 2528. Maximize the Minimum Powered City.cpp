class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n, i + r + 1);
            cnt[left] += stations[i];
            cnt[right] -= stations[i];
        }

        auto check = [&](long long val) -> bool {
            vector<long long> diff = cnt;
            long long sum = 0;
            long long remaining = k;

            for (int i = 0; i < n; i++) {
                sum += diff[i];
                if (sum < val) {
                    long long add = val - sum;
                    if (remaining < add) {
                        return false;
                    }
                    remaining -= add;
                    int end = min(n, i + 2 * r + 1);
                    diff[end] -= add;
                    sum += add;
                }
            }
            return true;
        };

        long long l= ranges::min(stations);
        long long h= accumulate(stations.begin(), stations.end(), 0LL) + k;
        long long ans = 0;
        while (l<= h) {
            long long mid = l+ (h - l) / 2;
            if (check(mid)) {
                ans = mid;
                l= mid + 1;
            } else {
                h= mid - 1;
            }
        }
        return ans;
    }
};
