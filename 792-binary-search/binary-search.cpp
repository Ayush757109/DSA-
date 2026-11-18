class Solution {
public:
int binarysearch(vector<int>&arr, int s, int e , int trgt){
    if(s>e){
        return -1;
    }
    int mid = (s+e)/2;
    if(arr[mid]==trgt){
        return mid;
    }

    if(arr[mid]>trgt){
        int recAns = binarysearch(arr ,s, mid-1 , trgt);
        return recAns;
    }
    else{
        int recAns = binarysearch(arr , mid+1,e,trgt);
        return recAns;
    }  
}
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int ans =  binarysearch(nums , start , end , target);
        return ans;
    }
};