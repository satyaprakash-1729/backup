#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int a,int b){
    return (a>b);
}

int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n>>k;
    int C[n];
    for(int i=0;i<n;i++){
        cin>>C[i];
    }
    sort(C,C+n,comp);
    int taken[k]={0};
    int ans=0;
    int y=0;
    for(int i=0;i<n;i++){
        ans+=(taken[y]+1)*C[i];
        taken[y]++;
        y=(y+1)%k;
    }
    cout<<ans<<endl;
    return 0;
}