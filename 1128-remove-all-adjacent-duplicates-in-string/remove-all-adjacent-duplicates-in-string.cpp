class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for(int i=0;i<s.length();i++){
            char ch = s[i];
        if(ans.empty()){
            ans.push_back(ch);
        }
        else if(ch !=ans.back()){
            ans.push_back(ch);
        }
        else{
            ans.pop_back();
        }
        }
        return ans;
    }
};