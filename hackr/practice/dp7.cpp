#include <iostream>
#include <algorithm>
#define MAXCOL 1000
using namespace std;

int eggDP(int ansMat[][MAXCOL],int a,int b){
    for(int i=1;i<b+1;i++){
        ansMat[1][i]=i;
    }
    for(int i=1;i<a+1;i++){
        ansMat[i][0]=0;
        ansMat[i][1]=1;
    }
    for(int n=2;n<=a;n++){
        for(int k=2;k<=b;k++){
            int minimum = 100000;
            for(int l = 1; l<=k; l++){
                int temp = max(ansMat[n-1][l-1],ansMat[n][k-l]);
                if(temp<minimum){
                    minimum = temp;
                }
            }
            ansMat[n][k] = minimum;
        }
    }
    for(int n=1;n<=a;n++){
        for(int k=1;k<=b;k++){
            cout<<ansMat[n][k]<<" ";
        }
        cout<<endl;
    }
    return ansMat[a][b];
}

int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n>>k;
    int ansMat[n+1][MAXCOL]={0};
    cout<<eggDP(ansMat,n,k)<<endl;
    return 0;
}