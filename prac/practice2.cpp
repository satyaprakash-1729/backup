#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int m,n;
    cin>>m>>n;
    char X[m];
    char Y[n];
    for(int i=0;i<m;i++){
        cin>>X[i];
    }
    for(int i=0;i<n;i++){
        cin>>Y[i];
    }
    int ans[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            ans[i][j]=0;
            //cout<<ans[i][j]<<"\t\t";
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]){
                ans[i][j] = ans[i-1][j-1]+1;
            }else{
                ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
            }
        }
    }
    int i=m;
    int j=n;
    char answer[ans[m][n]+1];
    int r = ans[m][n]-1;
    while(r>=0 && j>0){
        if(ans[i][j-1]==ans[i][j]-1){
            answer[r--] = Y[j-1];
        }
        j--;
    }
    answer[ans[m][n]] = '\0';
    cout<<answer<<endl;
    return 0;
}