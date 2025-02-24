#include<vector>
#include<iostream>
using namespace std;
void mergesort(vector<int> &);
void merge(vector<int> &,vector<int>&,vector<int>&);
int main(){
    int n;
    cin>>n;
    vector<int> vec;
    while(n--){
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    mergesort(vec);
    for(int i:vec){
        cout<<i<<" ";
    }
    return 0;
}