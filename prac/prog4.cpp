#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int t,n;
    cin>>t;
    for(int j=0;j<t;j++){
        cin>>n;
        bool arr[n];
        int firstNot=-1;
        int zer = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(!arr[i]){
                zer++;
            }
            if(!arr[i] && firstNot==-1){
                firstNot=i;
            }
        }
        if(firstNot==-1){
            cout<<0<<endl;
            continue;
        }
        cout<<(n-firstNot)*100 + zer*1000<<endl;
    }
    return 0;
}