class Solution {
public:
int solveRec(vector<int>& nums , int curr,int prev,vector<vector<int>>&dp){
    if(curr>=nums.size()){
        return 0;
    }
    if(dp[curr][prev+1]!=-1){
      return  dp[curr][prev+1];
    }
    int includeAns = 0;
    if(prev==-1 || nums[curr]>nums[prev]){
        includeAns = 1+ solveRec(nums , curr+1 , curr , dp);
    }
    int excludeAns = solveRec(nums , curr+1, prev, dp);
    int ans = max(includeAns , excludeAns);
    dp[curr][prev+1] = ans;
    return dp[curr][prev+1];
    
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       int prev=-1;
       int curr = 0;
       vector<vector<int>>dp(n ,vector<int>(n+1 ,-1));
     return  solveRec(nums , curr ,prev,dp )  ;
    }
    
};