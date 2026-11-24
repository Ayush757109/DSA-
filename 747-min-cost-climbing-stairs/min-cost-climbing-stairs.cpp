
class Solution {
public:

    int solve(vector<int>& cost, int i, vector<int>& dp) {

        int n = cost.size();

        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int oneStep = solve(cost, i + 1, dp);
        int twoStep = solve(cost, i + 2, dp);

        return dp[i] = cost[i] + min(oneStep, twoStep);
    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        vector<int> dp(n, -1);

        return min(solve(cost, 0, dp),
                   solve(cost, 1, dp));
    }
};
