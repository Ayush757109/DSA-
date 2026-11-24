class Solution {
public:
int solve(vector<int>& nums , int indx, int end,vector<int> &dp){
    if(indx >end){
        return 0;
    }
    if(dp[indx]!=-1){
        return dp[indx];
    }
    int includeAns = nums[indx] + solve(nums , indx+2 ,  end , dp);
    int excludeAns  = solve(nums , indx+1 , end , dp);
    return  dp[indx] = max(includeAns , excludeAns) ;
    
}
    int rob(vector<int>& nums) {
        int n  =nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp(n+1 ,-1);
        int index = 0;
        int case1 = solve(nums, 0, n - 2, dp);
        fill(dp.begin(), dp.end(), -1);
        int case2 = solve(nums, 1, n - 1 ,dp);
        return max(case1, case2);
        
    }
};