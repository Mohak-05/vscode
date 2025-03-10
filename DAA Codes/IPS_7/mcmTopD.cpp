#include<iostream>
#include<vector>
#include<string>
#include<climits>

using namespace std;

struct parRes{
    string par;
    int cost;
};

vector<vector<parRes>> dp;

parRes mcmTD(int i, int j, vector<int>& dim, vector<string>& matnames){
    if(i==j){
        return {matnames[i-1],0};
    }
    if(dp[i][j].cost!=-1){
        return dp[i][j];
    }
    parRes best={"",INT_MAX};
    for(int k=i;k<j;k++){
        parRes l=mcmTD(i,k,dim,matnames);
        parRes r=mcmTD(k+1,j,dim,matnames);
        int cost = l.cost + r.cost + (dim[i-1] * dim[k] * dim[j]);
        if(cost < best.cost){
            best.cost = cost;
            best.par = "(" + l.par + "*" + r.par + ")";
        }
    }
    return dp[i][j] = best;
}

int main(){
    int n = 4;
    vector<int> dim = {10, 30, 20, 40};
    vector<string> matnames = {"A1", "A2", "A3"};
    
    dp.assign(n, vector<parRes>(n, {"", -1}));
    parRes res = mcmTD(1, n-1, dim, matnames);
    
    cout << "Optimal Parenthesization: " << res.par << endl;
    cout << "Minimum Cost: " << res.cost << endl;
    
    return 0;
}