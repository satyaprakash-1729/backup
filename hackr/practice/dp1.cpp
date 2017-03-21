#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    int coins[m];
    for(int i=0;i<m;i++){
        cin>>coins[i];
    }
    sort(coins,coins+m);
    int numberOfWays[n+1]={0};
    numberOfWays[0]=1;
    for(int i=0;i<m;i++){
        for(int j=coins[i];j<=n;j++){
            numberOfWays[j]+=numberOfWays[j-coins[i]];
        }
    }
    cout<<numberOfWays[n]<<endl;
    return 0;
}