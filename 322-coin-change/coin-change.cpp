class Solution {
public:
 int solve(vector<int>& coins ,int amount ,vector<int>&dp){
    if(amount==0) return 0;
      if(amount < 0){
        return INT_MAX;
      }
      if(dp[amount]!=-1){
        return dp[amount];
      }
    int ans=INT_MAX;
      for(int i=0;i<coins.size();i++){
        int coin = coins[i];
        int res = solve(coins, amount-coin , dp);
        if(res!=INT_MAX){
           ans = min(ans , 1+res);
        }
    }
    return  dp[amount] = ans;;
 }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+111 , -1);
       int uttr= solve(coins , amount , dp);
        if(uttr== INT_MAX) return -1;
       return uttr;
    }
};