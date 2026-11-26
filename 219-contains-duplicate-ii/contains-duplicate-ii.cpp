class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         int n = nums.size();
           unordered_set<int> st;
           int i=0;
           for(int j=0;j<n;j++){
            if(st.count(nums[j])){
                return true;
            }
             st.insert(nums[j]);
            if(j-i>=k){
              st.erase(nums[i]);
              i++;
            }
             }
            
       return false;
       
    }
};