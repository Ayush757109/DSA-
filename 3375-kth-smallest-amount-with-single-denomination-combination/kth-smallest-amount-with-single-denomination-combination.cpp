class Solution {
public:
    using ll = long long;

    ll lcm_ll(ll a, ll b) {
        return a / std::gcd(a, b) * b;
    }

    ll countAmounts(ll x, const vector<int>& coins) {
        int n = coins.size();
        ll ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            ll L = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    L = lcm_ll(L, coins[i]);

                    // No multiple of L can be <= x.
                    if (L > x) {
                        L = x + 1;
                        break;
                    }
                }
            }

            if (L > x)
                continue;

            ll cnt = x / L;

            if (bits % 2 == 1)
                ans += cnt;
            else
                ans -= cnt;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll lo = 1;
        ll hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;

            if (countAmounts(mid, coins) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};