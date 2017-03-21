#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        long c,d,l;
        cin>>c>>d>>l;
        if(l%4!=0){
            cout<<"no"<<endl;
            continue;
        }
        if(4*(c+d)<l){
            cout<<"no"<<endl;
            continue;
        }
        long least=0;
        if(d*2 >= c){
            least = d;
        }else{
            least = d + (c-(d*2));
        }
        cout<<"--"<<l<<"--"<<least*4<<endl;
        if(l >= least*4){
            cout<<"yes"<<endl;
        }else{
            cout<<"no2"<<endl;
        }
    }
    return 0;
}