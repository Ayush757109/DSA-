class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left =0, right =0, count =0;
        int zerocnt = 0;
        for(int right =0;right<n;right++){
            if(nums[right] ==0){
                zerocnt++;
            }
            while(zerocnt >k){
                if(nums[left]==0){
                    zerocnt--;
                }
                left++;
            } 
            
            count = max(count , right-left +1);
        }
        return count;
    }
};