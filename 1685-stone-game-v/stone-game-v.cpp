class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // Prefix sum: sum of [l..r] =
        // prefix[r + 1] - prefix[l]
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // len = length of current row
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                // Split:
                // left  = [l ... k]
                // right = [k+1 ... r]
                for (int k = l; k < r; k++) {
                    long long leftSum =
                        prefix[k + 1] - prefix[l];

                    long long rightSum =
                        prefix[r + 1] - prefix[k + 1];

                    if (leftSum < rightSum) {
                        // Bob removes right, so left remains.
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + dp[l][k]
                        );
                    }
                    else if (leftSum > rightSum) {
                        // Bob removes left, so right remains.
                        dp[l][r] = max(
                            dp[l][r],
                            rightSum + dp[k + 1][r]
                        );
                    }
                    else {
                        // Equal sums: Alice chooses which side remains.
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + max(
                                dp[l][k],
                                dp[k + 1][r]
                            )
                        );
                    }
                }
            }
        }

        return (int)dp[0][n - 1];
    }
};