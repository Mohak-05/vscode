#include<iostream>
#include<vector>
#include<algorithm>
//(this is for using max,min etc)

using namespace std;

int bf_LCS(vector<char> p, vector<char> q,int n, int m,vector<char> & res ){
    if (n==0||m==0){
        return 0;
    }
    else if (p[n-1]==q[m-1]){
        res.push_back(p[n-1]);
        return 1+bf_LCS(p,q,n-1,m-1,res);
    }
    else{
        int tmp1=bf_LCS(p,q,n,m-1,res);
        int tmp2=bf_LCS(p,q,n-1,m,res);
        return max(tmp1,tmp2);
    }
}

int mem_rec(vector<char> p, vector<char> q,int n, int m,vector<char> & res,vector<vector<int>>& memo){
    if(memo[n][m]!=-1){
        return memo[n][m];
    }
    int result;
    if (n==0||m==0){
        memo[n][m]=0;
        result= 0;
    }
    else if (p[n-1]==q[m-1]){
        res.push_back(p[n-1]);
        result= 1+mem_rec(p,q,n-1,m-1,res,memo);
    }
    else{
        int tmp1=mem_rec(p,q,n,m-1,res,memo);
        int tmp2=mem_rec(p,q,n-1,m,res,memo);
        result= max(tmp1,tmp2);
    }
    memo[n][m]=result;
    return result;
}

int bot_up(vector<char> p, vector<char> q,int n,int m,vector<char>& res){
    vector<vector<int>> memo(n+1,vector<int>(m+1,0));
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(p[i-1]==q[j-1]){
                memo[i][j]=memo[i-1][j-1]+1;
            }
            else {
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }

    int i = n, j = m;
    res.clear();
    
    while(i > 0 && j > 0){
        if(p[i-1] == q[j-1]){
            res.push_back(p[i-1]);
            i--; j--;
        } else if(memo[i-1][j] > memo[i][j-1]){
            i--;
        } else {
            j--;
        }
    }

    return memo[n][m];
}

int main(){
    int n, m;
    vector<char> p,q,res1,res2,res3;
    cin>>n;
    for(int i=0;i<n;i++){
        char tem;
        cin>>tem;
        p.push_back(tem);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        char tem;
        cin>>tem;
        q.push_back(tem);
    }

    vector<vector<int>> memo(n+1,vector<int>(m+1,-1));

    int len1=bf_LCS(p,q,n,m,res1);
    int len2=mem_rec(p,q,n,m,res2,memo);
    int len3=bot_up(p,q,n,m,res3);

    reverse(res1.begin(), res1.end());
    reverse(res2.begin(), res2.end());
    reverse(res3.begin(), res3.end());
    
    cout<<len1<<endl;
    return 0;
}
