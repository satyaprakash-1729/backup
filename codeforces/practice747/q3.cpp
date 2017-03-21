#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,q;
    cin>>n>>q;
    int occupied[n+1]={0};
    int t,k,d;
    for(int i=0;i<q;i++){
        int done[n+1]={0};
        int prev[n+1]={0};
        cin>>t>>k>>d;
            int y = k;
            int ans=0;
            for(int j=1;j<=n;j++){
                if(occupied[j]<=t && y>0){
                    prev[j]=occupied[j];
                    done[j]=1;
                    occupied[j]=t+d;
                    ans += j;
                    y--;
                }else{
                    continue;
                }
            }
            if(y>0){
                //printf("---------%d\n",y );
                for(int j=1;j<=n;j++){
                    if(done[j]){
                        occupied[j]=prev[j];
                    }
                }
                cout<<-1<<endl;
            }else{
                cout<<ans<<endl;
            }
    }
    return 0;
}