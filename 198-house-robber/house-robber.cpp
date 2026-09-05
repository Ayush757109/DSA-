
class Solution {
public:
    int solveUsingDP(vector<int>& nums, int index, vector<int>& dp) {
        if (index >= nums.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int include = nums[index] + solveUsingDP(nums, index + 2, dp);
        int exclude = solveUsingDP(nums, index + 1, dp);

        dp[index] = max(include, exclude);

        return dp[index];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return solveUsingDP(nums, 0, dp);
    }
};
