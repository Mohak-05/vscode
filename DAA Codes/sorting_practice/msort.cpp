#include<iostream>
#include<vector>
using namespace std;
void mergesort(vector<int> &);
void merge(vector<int> &,vector<int> &,vector<int> &);
int main(){
    vector<int> arr{23,14,56,28,7,18,92,78,20};
    mergesort(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}
void mergesort(vector<int> &arr){
    if (arr.size()<=1){
        return;
    }
    vector<int> left(arr.begin(),arr.begin()+arr.size()/2);
    vector<int> right(arr.begin()+arr.size()/2,arr.end());
    mergesort(left);
    mergesort(right);
    merge(arr,left,right);
}
void merge(vector<int> &arr,vector<int> &left,vector<int> &right){
    int i=0,l=0,r=0;
    while(l<left.size() && r<right.size()){
        if (left[l] < right[r]){
            arr[i++]=left[l++];
        }
        else{
            arr[i++]=right[r++];
        }
    }
    while(l<left.size()){
        arr[i++]=left[l++];
    }
    while(r<right.size()){
        arr[i++]=right[r++];
    }
}