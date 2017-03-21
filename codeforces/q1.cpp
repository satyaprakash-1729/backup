#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    if(n%2==0){
        int k = n/2;
        cout<<k<<endl;
        for(int i=0;i<k;i++){
            cout<<2<<" ";
        }
        cout<<endl;
    }else{
        int k = ((n-3)/2)+1;
        cout<<k<<endl;
        for(int i=0;i<k-1;i++){
            cout<<2<<" ";
        }
        cout<<3<<endl;
    }
    return 0;
}