#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

bool oddHacko(long n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 0;
    }
    bool arr[7]={1,0,0,1,1,1,0};
    int r = (n-3)%7;
    return arr[r];
}

int main()
{   
    int n,q,ang;
    cin>>n>>q;
    char arr[n+1][n+1];
    for(long i=1;i<=n;i++){
        for(long j=1;j<=n;j++){
            arr[i][j]=oddHacko((i*j)*(i*j))?'Y':'X';
        }
    }
    for(int i=0;i<q;i++){
        cin>>ang;
        ang = ang%360;
        if(ang==0){
            cout<<0<<endl;
        }else if(ang==90){
            int ans=0;
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(arr[j][k]!=arr[k][n+1-j]){
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }else if(ang==180){
            int ans=0;
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    //cout<<arr[n-j+1][n-k+1]<<" ";
                    if(arr[j][k]!=arr[n-j+1][n-k+1]){
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }else if(ang==270){
            int ans=0;
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(arr[j][k]!=arr[n-j+1][k]){
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}