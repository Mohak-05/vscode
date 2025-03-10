#include<iostream>
#include <vector>
#include <string>

using namespace std;

struct parRes{
    string par;
    int cost;
};

vector<parRes> mcmBF(int i,int j,vector<int>& dim, vector<string>& matnames ){
    vector<parRes> results;
    if(i==j){
        results.push_back({matnames[i-1],0});
        return results;
    }
    for(int k=i;k<j;k++){
        vector<parRes> lResults,rResults;
        lResults=mcmBF(i,k,dim,matnames);
        rResults=mcmBF(k+1,j,dim,matnames);
        for(const auto&l:lResults){
            for(const auto&r:rResults){
                int cost=l.cost+r.cost+(dim[i-1]*dim[k]*dim[j]);
                string res="("+l.par+"*"+r.par+")";
                results.push_back({res,cost});
            }
        }
    }
    return results;
}

int main(){
    int n=4;
    vector <int> dim{10,30,20,40};
    vector <string> matnames{"A1","A2","A3"};

    vector<parRes> res= mcmBF(1,n-1,dim,matnames);

    cout<<res.size()<<endl;
    for (const auto& r:res){
        cout<<r.par<<endl<<r.cost<<endl;
    }
    
    return 0;
}