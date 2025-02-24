#include<stdio.h>
#include<stdlib.h>

void xorop(int *temp,int* gen,int gl){
    for(int i=0;i<(gl);i++){
        temp[i]^=gen[i];
    }
}
void crc(int * data,int* gen,int dl,int gl,int* opt){
    for(int i=0;i<(dl+gl-1);i++){
        if(i<dl){
        opt[i]=data[i];
        }
        else{
            opt[i]=0;
        }
    }
    for(int i=0;i<dl;i++){
        if(opt[i]==1){
            xorop(&opt[i],gen,gl);
        }
    }

}

int main(){
    
    int data[]={1,0,0,1,1};
    int gen[]={1,0,1,1};
    
    int gl=sizeof(gen)/sizeof(gen[0]);
    int dl=sizeof(data)/sizeof(data[0]);
    
    int opt[dl+gl-1];
    crc(data,gen,dl,gl,opt);
    for(int i=0;i<(dl+gl-1);i++){
        printf("%d",opt[i]);
    }

    return 0;
}