class Solution {
public:
    static constexpr int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m + 1), down(m + 1);
        vector<int> prefUp(m + 1), prefDown(m + 1);
        vector<int> nxtUp(m + 1), nxtDown(m + 1);

        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        for (int len = 3; len <= n; len++) {
            prefUp[0] = prefDown[0] = 0;

            for (int i = 1; i <= m; i++) {
                prefUp[i] = prefUp[i - 1] + up[i];
                if (prefUp[i] >= MOD) prefUp[i] -= MOD;

                prefDown[i] = prefDown[i - 1] + down[i];
                if (prefDown[i] >= MOD) prefDown[i] -= MOD;
            }

            int totalUp = prefUp[m];

            for (int z = 1; z <= m; z++) {
                nxtUp[z] = prefDown[z - 1];

                nxtDown[z] = totalUp - prefUp[z];
                if (nxtDown[z] < 0) nxtDown[z] += MOD;
            }

            up.swap(nxtUp);
            down.swap(nxtDown);
        }

        long long ans = 0;
        for (int v = 1; v <= m; v++) {
            ans += up[v];
            ans += down[v];
        }

        return (int)(ans % MOD);
    }
};