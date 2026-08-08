class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low  =0;
        int high  = nums.size()-1;
        while(low < high){
            int mid = high +(low-high)/2;
             if (nums[mid-1] < nums[mid]){
                low = mid;
            }
            else {
                high = mid-1;
            }
        }
        return low;
        
    }
};