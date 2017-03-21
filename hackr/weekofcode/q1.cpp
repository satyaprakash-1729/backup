#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,t;
    cin>>n>>t;
    int c[t];
    for(int i =0;i<t;i++){
        cin>>c[i];
    }
    int ans = 0;
    int left = n;
    for(int i=0;i<t;i++){
        if(left-c[i]<5 && i<t-1){
            ans+=(n-left+c[i]);
            left = n;
        }else{
            left-=c[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}