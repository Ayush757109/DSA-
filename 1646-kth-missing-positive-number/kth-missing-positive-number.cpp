class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missingNumber  = k;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>missingNumber){
                return missingNumber;
            }
            else{
                missingNumber++;
            }
        }
        return missingNumber;
    }
};