class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> dp(n + 1, INT_MAX);

        int left = 0;
        long long sum = 0;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Carry forward the best subarray found so far
            dp[right + 1] = dp[right];

            if (sum == target) {
                int len = right - left + 1;

                // Find a previous non-overlapping subarray
                if (dp[left] != INT_MAX) {
                    ans = min(ans, len + dp[left]);
                }

                // Update best subarray length
                dp[right + 1] = min(dp[right + 1], len);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};