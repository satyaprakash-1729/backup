#include <iostream>

using namespace std;

int recursive_dp(int arr[],int n,int i,int last){
    if(i==n){
        return 0;
    }
    if(arr[i]>last){
        return (max(1+recursive_dp(arr,n,i+1,arr[i]),recursive_dp(arr,n,i+1,last)));
    }else{
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    return 0;
}