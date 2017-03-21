#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,p;
    cin>>n>>p;
    if(n%2==1){
        cout<<min(p/2,(n-p)/2)<<endl;
    }else{
        if(p%2==0){
            cout<<min(p/2,(n-p)/2)<<endl;
        }else{
            cout<<min(p/2,((n-p)/2)+1)<<endl;
        }
    }
    return 0;
}