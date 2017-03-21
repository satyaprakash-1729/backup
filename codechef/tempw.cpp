#include <iostream>
#include <algorithm>
#define MAXNODE 50001
using namespace std;

int finder(vector<vector<int>> adj,int n,int v,int p[]){
    int max = 0;
    int ind=1;
    for(int i=1;i<=n;i++){
        if(!adj[v][i] && i!=v && p[i]>max){
            max = p[i];
            ind = i;
        }
    }
    return ind;
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        int p[n+1];
        vector<vector<int>> adj(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            cin>>p[i];
        }
        int a,b;
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            adj[a][b]=1;
            adj[b][a]=1;
        }
        for(int i=1;i<=n;i++){
            cout<<finder(adj,n,i,p)<<" ";
        }
        cout<<endl;
    }
    return 0;
}