#include <iostream>
#include <vector>

using namespace std;

int countInversions(vector <int> &);
int countAndMerge(vector <int> &, vector <int> &, vector <int> &);
int main(){
    vector <int> arr{1, 2, 9, 0, -1};
    cout << countInversions(arr) << endl;
    return 0;
}
int countInversions(vector <int> &arr){
    if(arr.size() <= 1){
        return 0;
    }
    int res = 0;
    vector <int> left;
    vector <int> right;
    for(int i = 0; i < arr.size(); i++){
        if(i < arr.size()/2){
            left.push_back(arr[i]);
        }
        else{
            right.push_back(arr[i]);
        }
    }
    res += countInversions(left) + countInversions(right);
    return res + countAndMerge(arr, left, right);
}
int countAndMerge(vector <int> &arr, vector <int> &left, vector <int> &right){
    int l = 0, r = 0, i = 0, res = 0;
    while(l < left.size() && r < right.size()){
        if(left[l] < right[r]){
            arr[i++] = left[l++];
        }
        else{
            arr[i++] = right[r++];
            res += left.size()-l;
        }
    }
    while(l < left.size()){
        arr[i++] = left[l++];
    }
    while(r < right.size()){
        arr[i++] = right[r++];
    }
    return res;
}