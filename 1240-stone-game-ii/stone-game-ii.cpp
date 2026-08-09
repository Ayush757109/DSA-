class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // suffix[i] = total stones from i to the end
        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // dp[i][M] = maximum stones current player can obtain
        // starting at i with current M
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int M = 1; M <= n; ++M) {

                // Can take all remaining piles
                if (2 * M >= n - i) {
                    dp[i][M] = suffix[i];
                    continue;
                }

                int best = 0;

                for (int X = 1; X <= 2 * M; ++X) {
                    int next_M = max(M, X);

                    // Current player's score =
                    // total remaining - opponent's best score
                    int score = suffix[i] - dp[i + X][next_M];

                    best = max(best, score);
                }

                dp[i][M] = best;
            }
        }

        return dp[0][1];
    }
};