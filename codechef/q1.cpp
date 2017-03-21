#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    long long a;
    cin>>a;
    while(a/10){
        int temp=1;
        int factor=10;
        while(a){
            if(a%10){
                temp*=(a%10);
            }
            a=a/10;
        }
        a=temp;
    }
    cout<<a<<endl;
    return 0;
}