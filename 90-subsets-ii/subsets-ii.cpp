class Solution {
public:
   void subset(vector<int>&nums , int indx , vector<int>output ,vector<vector<int>> &ans){
    if(indx>=nums.size()){
        ans.push_back(output);
        return ;
    }
    output.push_back(nums[indx]);
    subset(nums ,indx+1 , output , ans);
    output.pop_back();
    while(indx+1<nums.size() && nums[indx]==nums[indx+1]){
        indx++;
    }
      subset(nums ,indx+1 , output , ans );

   };
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int>output;
        int indx =0;
       subset(nums , indx , output, ans);
       return ans;
    }
};