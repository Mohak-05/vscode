#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> mvec,cvec;
    int csum=0,msum=0;
    for(int i=0;i<n;i++){
        int tem;
        scanf("%d",&tem);
        if (tem>csum+tem){
            csum=tem;
            cvec.clear();
        }
        else{
            csum+=tem;
        }
        cvec.push_back(tem);
        if (csum>msum || (csum==msum && cvec.size()<mvec.size())){
            msum=csum;
            mvec=cvec;
        }
    }
    for(int i=0;i<mvec.size();i++){
        printf("%d ",mvec[i]);
    }
}