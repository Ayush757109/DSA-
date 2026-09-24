class Solution {
public:
    char repeatedCharacter(string s) {
        map<char,int>mpp;
        int n=s.size();
        char ans;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(mpp.find(ch)!=mpp.end()){
                ans=ch;
                break;
            }else{
                mpp[ch]++;
            }
        }
        return ans;
    }
};