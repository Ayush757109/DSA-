class Solution {
public:
    vector<int> dp;

    int solveUsingDP(vector<int>& nums, int index, int end) {
        if (index >end) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int include = nums[index] + solveUsingDP(nums, index + 2, end);
        int exclude = solveUsingDP(nums, index + 1,end);

        return dp[index] = max(include, exclude);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        dp.assign(n, -1);
        int ans1 = solveUsingDP(nums, 0, n - 2);
         dp.assign(n, -1); 
         int ans2 = solveUsingDP(nums, 1, n - 1);
        return max(ans1, ans2);
    }
};