#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string a;
    cin>>a;
    int count[7]={0};
    for(int i=0;i<a.length();i++){
        if(a[i]=='B'){
            count[0]++;
        }
        if(a[i]=='u'){
            count[1]++;
        }
        if(a[i]=='l'){
            count[2]++;
        }
        if(a[i]=='b'){
            count[3]++;
        }
        if(a[i]=='a'){
            count[4]++;
        }
        if(a[i]=='s'){
            count[5]++;
        }
        if(a[i]=='r'){
            count[6]++;
        }
    }
    count[4]=count[4]/2;
    count[1]=count[1]/2;
    int mina = 1<<30;
    for(int i=0;i<7;i++){
        //cout<<"--"<<count[i]<<endl;
        if(count[i]<mina){
            mina = count[i];
        }
    }
    cout<<mina<<endl;
    return 0;
}