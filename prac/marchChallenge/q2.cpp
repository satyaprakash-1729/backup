#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    long t,n;
    cin>>t;
    for(int z=0;z<t;z++){
        cin>>n;
        long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int c = arr[0];
        bool flag = 0;
        for(int i=1;i<n;i++){
            if(arr[i]==c){
                cout<<arr[i]<<endl;
                flag = 1;
                break;
            }else{
                c = arr[i];
            }
        }
        if(flag){
            continue;
        }
        if(arr[0]+1!=arr[1]){
            cout<<arr[0]<<endl;
            continue;
        }
        if(arr[n-2]+1!=arr[n-1]){
            cout<<arr[n-1]<<endl;
            continue;
        }
    }
    return 0;
}