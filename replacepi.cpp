#include<iostream>
#include<string>
using namespace std;
string replcepi(string & str, int indx){
    if(indx>=str.length()){
        return "";
    }
    if(indx+1<str.length() &&
     str[indx]=='p' && str[indx+1]=='i'){
        return "3.14" +replcepi(str , indx+2);
    }
    return str[indx] +replcepi(str, indx+1);
}
int main(){
    string str = "pip";
    int indx = 0;
     cout<< replcepi(str,indx);
}