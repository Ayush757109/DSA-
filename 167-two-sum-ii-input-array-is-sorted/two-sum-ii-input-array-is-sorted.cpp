class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0 , end = numbers.size()-1 ;
       while(start<end){
        int ans = numbers[start] + numbers[end];
        if(ans<target){
            start++;
        }  
        else if (ans>target){
            end--;
        }  
        else{
            return {start+1 , end+1} ;
        }
        
    }
      return {};
    }
};