#include<iostream>
#include<vector>
#include<climits>
#include<string>

using namespace std;

struct parRes{
    string par;
    int cost;
};

string constructPar(int i, int j, vector<vector<int>>& s, vector<string> matnames){
    if (i==j){
        return matnames[i-1];
    }
    return "(" + constructPar(i,s[i][j],s,matnames)+"*"+constructPar(s[i][j]+1,j,s,matnames)+")"; 
}

parRes botUp(vector<int> & dim,vector<string>& matnames){
    
    int n=matnames.size();
    
    vector<vector<int>> m(n+1,vector<int>(n+1,0));
    vector<vector<int>> s(n+1,vector<int>(n+1,0));
    
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            
            int j=i+l-1;
            m[i][j]=INT_MAX;

            for(int k=i;k<j;k++){
                int cost=m[i][k]+m[k+1][j]+(dim[i-1]*dim[k]*dim[j]);
                if (cost<m[i][j]){
                    m[i][j]=cost;
                    s[i][j]=k;
                }
            }
        }
    }
    string optPara=constructPar(1,n,s,matnames);

    return {optPara,m[1][n]};
}

int main(){
    int n=4;
    vector <int> dim{10,30,20,40};
    vector <string> matnames{"A1","A2","A3"};

    parRes res= botUp(dim,matnames);

    cout<<res.par<<endl<<res.cost<<endl;
    
    return 0;
}

// ALTERNATE way of TAKING INPUT and doin MAIN FUNCTION
// int main(){
//     int n;
//     cin>>n;
//     vector<int> dim(n);
//     for(int i=0;i<n;i++){
//         cin>>dim[i];
//     }
//     vector<string> matnames; 
//     for(int i=1;i<n;i++){
//         matnames.push_back("A"+to_string(i));
//     }
//     parRes res=botUp(dim,matnames);
//     cout<<res.cost<<endl<<res.par;
//     return 0;
// }
