#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr1[100000]={0};
    int n,p;
    cin>>n>>p;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    int j=0;
    while(j<n){
        int sent  = arr[j]%p?(arr[j]/p)+1:arr[j]/p;
        while(arr1[sent]){
            sent++;
        }
        arr1[sent]=1;
        ans+=sent;
        j++;
    }
    cout<<ans<<endl;
    return 0;
}