#include <iostream>
#include <stdio.h>
#define MAXWIDTH 751
using namespace std;

bool isSafe(char farm[][MAXWIDTH], bool done[][MAXWIDTH], int m,int n,int i,int j){
    if(i<0 || i>=m || j<0 || j>=n || farm[i][j]=='*' || done[i][j]){
        return 0;
    }
    return 1;
}

bool checker(char farm[][MAXWIDTH], bool done[][MAXWIDTH], int m,int n,int i,int j){
    for(int r=i-1;r<i+2;r++){
        for(int c=j-1;c<j+2;c++){
            if(r!=i || c!=j){
                if(isSafe(farm,done,m,n,r,c)){
                    return 0;
                }         
            }
        }
    }
    return 1;
}

int dfs_visit(char farm[][MAXWIDTH], bool done[][MAXWIDTH], int i, int j,int m,int n){
    done[i][j]=1;
    if(checker(farm,done,m,n,i,j)){
        return 1;
    }
    int a = 1;
    for(int r=i-1;r<i+2;r++){
        for(int c=j-1;c<j+2;c++){
            if(r!=i || c!=j){
                if(isSafe(farm,done,m,n,r,c)){
                    a+=dfs_visit(farm,done,r,c,m,n);
                }         
            }
        }
    }
    return a;
}

int dfs(char farm[][MAXWIDTH], bool done[][MAXWIDTH],int m,int n){
    int ans = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(isSafe(farm,done,m,n,i,j)){
                int r = dfs_visit(farm,done,i,j,m,n);
                //cout<<r<<endl;
                if(r>ans){
                    ans = r;
                }
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n,m;
    //cin>>n>>m;
    //freopen("inp.in","r+",stdin);
    scanf("%d",&n);
    scanf("%d",&m);
    char farm[m+1][MAXWIDTH];
    bool done[m+1][MAXWIDTH];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            done[i][j]=0;
            //cin>>farm[i][j];
            scanf(" %c",&farm[i][j]);
        }
    }
    cout<<dfs(farm,done,m,n)<<endl;
    return 0;
}