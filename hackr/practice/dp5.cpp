#include <iostream>
#define MAXCOL 1000
using namespace std;

int dp_cost(int cost[][MAXCOL],int i,int j){
    if(i==0 && j==0){
        return cost[0][0];
    }else if(i==0){
        return cost[i][j]+dp_cost(cost,i,j-1);
    }else if(j==0){
        return cost[i][j]+dp_cost(cost,i-1,j);
    }else{
        int a = dp_cost(cost,i-1,j);
        int b = dp_cost(cost,i,j-1);
        int c = dp_cost(cost,i-1,j-1);
        int d;
        if(a<b){
            if(a<c){
                d = a;
            }else{
                d = c;
            }
        }else{
            if(b<c){
                d = b;
            }else{
                d = c;
            }
        }
        return cost[i][j]+d;
    }
}

int main(int argc, char const *argv[])
{
    int m,n;
    cin>>m>>n;
    int cost[m][MAXCOL]={0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }
    cout<<dp_cost(cost,m-1,n-1)<<endl;
    return 0;
}