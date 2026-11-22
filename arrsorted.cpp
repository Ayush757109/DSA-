#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&arr , int indx){
    if(indx ==arr.size()-1)
    return 1;
    if(arr[indx]>arr[indx+1]){
        return 0;
    }
    return solve(arr , indx+1);
}

int main(){
    vector<int>arr{10,20,30,40,50};
    int index =0;
    int ans = solve(arr , index);
    if(ans == 1)
        cout << "Array is sorted";
    else
        cout << "Array is not sorted";

    return 0;
}