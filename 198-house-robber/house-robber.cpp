class Solution {
public:
int solveDP(vector<int>& nums , int indx,  vector<int>&dp){
    if(indx >=nums.size()){
        return 0;
    }
    if(dp[indx]!=-1){
        return dp[indx];
    }
    int includeAns = nums[indx]+solveDP(nums , indx+2,dp);
    int exclude = solveDP(nums , indx+1 , dp);
    int uttr = max(includeAns ,exclude );
    dp[indx] =  uttr;
    return dp[indx];
}
    int rob(vector<int>& nums) {
        int n  = nums.size();
        vector<int>dp(n+100 , -1);
       int index =0;
       int ans = solveDP(nums , index ,dp);
       return ans;
    }
};