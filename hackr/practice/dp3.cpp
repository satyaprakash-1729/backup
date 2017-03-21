#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t,n;
    cin>>t;
    for(int z=0;z<t;z++){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        float ans = 0.0;
        int k = 0;
        for(int i = 0;i<n;i++){
            ans += ((float)(n+1))/(n-k+1);
            if(arr[i]!=arr[i+1] || i==n-1){
                k=i+1;
            }
        }
        cout.precision(2);
        cout<<fixed<<ans<<endl;
    }
    return 0;
}