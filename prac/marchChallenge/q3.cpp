#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int t,n;
    cin>>t;
    for(int z=0;z<t;z++){
        cin>>n;
        int arr[n][n];
        int zero=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
                if(!arr[i][j]){
                    zero++;
                }
            }
        }
        zero = zero/2;
        int index=1;
        while(((index*index)+index)/2<=zero){
            index++;
        }
        index--;
        cout<<n-index-1<<endl;
    }
    return 0;
}