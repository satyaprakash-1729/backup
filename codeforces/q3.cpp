#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,g;
    cin>>g;
    for(int z=0;z<g;z++){
        cin>>n;
        int heaps[n];
        bool zero[n]={0};
        int x=0;
        for(int i=0;i<n;i++){
            cin>>heaps[i];
            x = x^heaps[i];
        }
        if(x==0){
            cout<<"L"<<endl;
            continue;
        }
        int player = 0;
        while(1){
            bool flag = 0;
            int notZero = -1;
            for(int i=0;i<n;i++){
                if(!zero[i]){
                    notZero = i;
                }
                if(heaps[i]^x < heaps[i]){
                    flag=1;
                    int y = heaps[i]^x;
                    heaps[i]=heaps[i]^x;
                    x = y^heaps[i];
                    break;
                }
            }
            if(x==0){
                if(player==0){
                    cout<<"W"<<endl;
                    break;
                }else{
                    cout<<"L"<<endl;
                    break;
                }
            }
            if(!flag){
                if(notZero==-1){
                    cout<<"L"<<endl;
                    break;
                }
                zero[notZero]=1;
            }
            player=!player;
        }
    }
    return 0;
}