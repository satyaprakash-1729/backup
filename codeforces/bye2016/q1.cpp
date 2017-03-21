#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n>>k;
    int left = 240;
    left -= k;
    int i=1;
    int j=0;
    while(left - 5*i >= 0 && j<n){
        //cout<<"-->"<<left<<endl;
        left -= 5*i;
        i++;
        j++;
    }
    cout<<j<<endl;
    return 0;
}