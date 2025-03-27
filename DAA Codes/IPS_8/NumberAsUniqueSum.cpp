#include<iostream>
#include<vector>

using namespace std;

void UniqueSum(int n,int i,int cursum, vector<int>& accures,vector<int> & res){
    if (cursum>n || i>=n){
        return;
    }
    if (cursum==n){
        if (accures.size()>res.size()){
            res=accures;
        }
        return;
    }
    vector<int> newres=accures;
    newres.push_back(i+1);
    UniqueSum(n,i+1,cursum,accures,res);
    cursum+=(i+1);
    UniqueSum(n,i+1,cursum,newres,res);
}

int main(){
    vector<int> res;
    vector<int> accures;
    UniqueSum(10,0,0,accures,res);
    for(auto i :res){
        cout<<i<<endl;
    }
    
    return 0;
}
