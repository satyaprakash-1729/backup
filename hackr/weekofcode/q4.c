#include <stdio.h>
#define MAXSIZE 5000

int min(int a, int b){
    return (a>b)?b:a;
}

int abs(int a){
    return (a<0)?(-a):a;
}

int func(int poles[][2], int n, int k, int last, int ansMat[][MAXSIZE][MAXSIZE]){
    if(ansMat[last][n][k]!=-1){
        return ansMat[last][n][k];
    }
    if(n==0 || k==0){
        int ans = 0;
        for(int i=0;i<last;i++){
            ans+=poles[i][1]*abs(poles[i][0]-poles[last][0]);
        }
        ansMat[last][n][k] = ans;
    }else{
         ansMat[last][n][k] = min(poles[n-1][1]*abs(poles[n-1][0]-poles[last][0]) + func(poles,n-1,k,last,ansMat),func(poles,n-1,k-1,n-1,ansMat));
    }
    return ansMat[last][n][k];
}

int main(int argc, char const *argv[])
{
    int n,k,a,b;
    scanf("%d",&n);
    scanf("%d",&k);
    int poles[n][2];
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        scanf("%d",&b);
        poles[n-i-1][0] = a;
        poles[n-i-1][1] = b;
    }
    static int ansMat[MAXSIZE][MAXSIZE][MAXSIZE];
    for(int i =0;i<n;i++){
        for(int j =0;j<MAXSIZE;j++){
            for(int l = 0;l<MAXSIZE;l++){
                ansMat[i][j][l]=-1;
            }
        }
    }
    printf("%d\n",func(poles,n-1,k-1,n-1,ansMat));
    return 0;
}