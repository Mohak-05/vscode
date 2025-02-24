#include<iostream>
#include<vector>
using namespace std;
int fp(vector<float> &arr,int low, int high){
    int i=low;
    int j=high;
    float pivot=arr[high];
    while(i<j){
        while(i<j && arr[i]<=pivot){
            i++;
        }
        while(i<j && arr[j]>=pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    arr[high]=arr[j];
    arr[j]=pivot;
    return j;
}
void qsort(vector<float> &arr,int low, int high, int k){
    if(low>=high){
        return;
    }
    int pivot=fp(arr,low,high);
    if (pivot==k){
        cout<<arr[pivot];
        return;
    }
    else if(pivot>k){
        qsort(arr,low,pivot-1,k);
    }
    else{
        qsort(arr,pivot+1,high,k);
    }
}
int main(){
    int n=5;
    vector<float> vec{1,5,4,3,2};
    int k=2;
    qsort(vec,0,n-1,k);
    return 0;
}