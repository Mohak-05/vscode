#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 PROBLEM DESCRIPTION
 -------------------

 Given an array containing the price of each cut of a rod,
 find the optimal way to cut it
Input: price[] =  [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation:  The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
*/


/*
 Naive Brute force Top down approach

 Recurrence relation,
 optimal = 0
 for j = 1 to i:
    optimal = max(optimal, prices[j-1]) + cutRod(i-j))
*/
int bf(vector<int> p, int s){
    if (s==0) return 0;
    int optimal=0;
    for(int i=1;i<=s;i++){
        optimal=max(optimal,p[i-1]+bf(p,s-i));
    }
    return optimal;
}
/*
Memoized approach, just use a memo table
*/

int topD(vector<int>& p,int s,vector<int>& memo){
    int n=s;
    if (s==0) return 0;
    if (memo[s]!=-1) return memo[s];
    int optimal=0;
    for(int i=1;i<=s;i++){
        optimal=max(optimal,p[i-1]+topD(p,s-i,memo));
    }
    memo[s]=optimal;
    return optimal;
}
/*
 Utilizing a bottom up approach with a dp table
 for i = 0 to n-1:
    for j = 1 to i:
        dp[i] = max(prices[j-1], dp[i-j])
*/
int botUP(vector<int>& p,int s){
    int n=s;
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i]=max(dp[i],dp[i-j]+p[j-1]);
        }
    }
    return dp[s];
}
void cuts(vector<int>& p,int s,vector<int>& cutsmade){
    int n=s;
    vector<int> dp(n+1,0);
    vector<int> cuts(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(dp[i]<dp[i-j]+p[j-1]){
                dp[i]=dp[i-j]+p[j-1];
                cuts[i]=j;
            }
        }
    }
    int index=n;
    while (index>0){
        cutsmade.push_back(cuts[index]);
        index-=cuts[index];
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> p(n,0);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    int s,price;
    cin>>s>>price;
    vector<int> cutsmade;
    cuts(p,s,cutsmade);
    vector<int> memo(s+1,-1);
    cout<<bf(p,s)-(price*(cutsmade.size()-1))<<endl;
    cout<<topD(p,s,memo)-(price*(cutsmade.size()-1))<<endl;
    cout<<botUP(p,s)-(price*(cutsmade.size()-1))<<endl;
    for(int i:cutsmade){
        cout<<i<<endl;
    }
    return 0;
}