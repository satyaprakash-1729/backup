#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n,m;
        cin>>n>>m;
        char str[n][m];
        bool flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>str[i][j];
                if(str[i][j]=='W'){
                    if(str[i][j-1]=='A'){
                        flag=1;
                    }
                    if(str[i-1][j]=='B'){
                        flag=1;
                    }
                }
                if(str[i][j]=='A'){
                    if(str[i][j-1]=='W'){
                        flag=1;
                    }
                    if(str[i-1][j]=='B' || str[i-1][j]=='W'){
                        flag=1;
                    }
                }
                if(j==m-1 || j==0){
                    if(str[i][j]=='W'){
                        flag=1;
                    }
                }
                if(i==n-1){
                    if(str[i][j]=='W'){
                        flag=1;
                    }
                }
            }
        }
        if(flag){
            cout<<"no"<<endl;
        }else{
            cout<<"yes"<<endl;
        }
    }
    return 0;
}