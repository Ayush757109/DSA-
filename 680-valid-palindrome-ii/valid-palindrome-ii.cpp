class Solution {
public:
bool checkPalldrm(string s , int i , int j){
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        else{
            i++,j--;
        }
    }
    return true;
}
    bool validPalindrome(string s) {
        int i =0;
        int j = s.length()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                bool CaseOne = checkPalldrm(s,i,j-1);
                bool CaseTwo = checkPalldrm(s,i+1,j);
                bool finalAns = CaseOne || CaseTwo;
                return finalAns;
            }
        }
        return true;
    }
};