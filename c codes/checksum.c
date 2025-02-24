#include<stdio.h>
#include<string.h>
void checksum(char* data,char res[],int bs){
    int n=strlen(data);
    memset(res,'0',bs);
    res[bs]='\0';
    for(int i=0;i<n;i+=bs){
        int c=0;
        for(int j=bs-1;j>=0;j--){
            int sum=(res[j]-'0')+(data[i+j]-'0')+c;
            c=sum/2;
            res[j]=sum%2+'0';
        }
        if(c){
            for(int j=bs-1;j>=0 && c;j--){
                int sum=(res[j]-'0')+c;
                c=sum/2;
                res[j]=sum%2+'0';
            }
        }
    }
    for(int i=0;i<bs;i++){
        res[i]=(res[i]=='0'?'1':'0');
    }
}
int main(){
    char data[]={'1','0','0','1','1','1','0','1','0','0','1','1','1','1','1','1','\0'};
    int blocks=4;
    char res[blocks+1];
    checksum(data,res,blocks);
    printf("checksum is:%s",res);
    return 0;
}