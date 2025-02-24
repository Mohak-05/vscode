#include<iostream>
#include<vector>
using namespace std;
void divide(vector<int>&,vector<int>&);
void conc(vector<int>&,vector<int>&,vector<int>&);
int main(){
    int n;
    cin>>n;
    vector<int> arr,uarr;
    for(int i=0;i<n;i++){
        int tem;
        cin>>tem;
        arr.push_back(tem);
    }
    divide(arr,uarr);
    for(int i=0;i<uarr.size();i++){
        cout<<uarr[i]<<"\n";
    }
    return 0;
}
void divide(vector<int> &arr,vector<int> &uarr){
    if (arr.size()<=1){
        return;
    }
    vector<int> left(arr.begin(),arr.begin()+arr.size()/2),luarr;
    vector<int> right(arr.begin()+arr.size()/2,arr.end()),ruarr;
    divide(left,luarr);
    divide(right,ruarr);
    conc(left,right,uarr);
}
void conc(vector<int> &left,vector<int> &right,vector<int> &uarr){
    for(int i=0;i<left.size();i++){
        if (left[i]>0){
            uarr.push_back(left[i]);
        }
    }
    for(int i=0;i<right.size();i++){
        if (right[i]>0){
            uarr.push_back(right[i]);
        }
    }
}
