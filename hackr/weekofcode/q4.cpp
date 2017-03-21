#include <iostream>
#include <vector>
#define MAXSIZE 5000
int abs(int a){
    return (a<0)?(-a):a;
}
using namespace std;

int func(int poles[][2], int n, int k, int last, vector<vector<vector<int>>> ansMat){
    if(ansMat[last][0][0]!=-1){
        return ansMat[last][0][0];
    }
    if(n==0 || k==0){
        int ans = 0;
        for(int i=0;i<last;i++){
            ans+=poles[i][1]*abs(poles[i][0]-poles[last][0]);
        }
        ansMat[last][1][1] = ans;
    }else{
         ansMat[last][1][1] = min(poles[n-1][1]*abs(poles[n-1][0]-poles[last][0]) + func(poles,n-1,k,last,ansMat),func(poles,n-1,k-1,n-1,ansMat));
    }
    ansMat[last][0][0] = ansMat[last][1][1];
    return ansMat[last][0][0];
}

int main(int argc, char const *argv[])
{
    int n,k,a,b;
    cin>>n>>k;
    int poles[n][2];
    for(int i=0;i<n;i++){
        cin>>a>>b;
        poles[n-i-1][0] = a;
        poles[n-i-1][1] = b;
    }
    vector<vector<vector<int> > > ansMat (MAXSIZE,vector<vector<int> >(2,vector <int>(2,-1)));
    /*for(int i =0;i<n;i++){
        for(int j =0;j<MAXSIZE;j++){
            for(int l = 0;l<MAXSIZE;l++){
                ansMat[i][j][l]=-1;
            }
        }
    }*/
    cout<<func(poles,n-1,k-1,n-1,ansMat)<<endl;
    //cout<<ansMat[n-1][n-1][k-1]<<endl;
    return 0;
}