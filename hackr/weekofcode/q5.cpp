#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int j = 0; j<q; j++){
        int left,right,x,y;
        cin>>left>>right>>x>>y;
        int count=0;
        for(int i=left;i<=right;i++){
            if(arr[i]%x==y){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}