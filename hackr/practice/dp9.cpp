#include <iostream>

using namespace std;

int dp(int arr[],int n,int k,int vals[]){
    if(vals[k]!=-1){
        return vals[k];
    }else if(k==0){
        vals[0]=0;
        return 0;
    }else if(k==1){
        vals[1] = arr[1];
        return arr[1];
    }else{
        int maxa=arr[k];
        int rt;
        //cout<<k<<endl;
        for(int l = 1;l<=k/2;l++){
            int y = dp(arr,n,k-l,vals)+dp(arr,n,l,vals);
            if(y>maxa){
                maxa = y;
                rt = l;
            }
        }
        vals[k] = maxa;
        return maxa;
    }
}

int dp2(int arr[],int n){
    int vals[n+1];
    vals[0]=0;
    for(int l = 1;l<=n;l++){
        int maxa = 0;
        for(int i=1;i<=l;i++){
            if(arr[i]+vals[l-i]>maxa){
                maxa = arr[i]+vals[l-i];
            }
        }
        vals[l] = maxa;
    }
    return vals[n];
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n;
    int arr[n+1];
    int vals[n+1]={-1};
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<dp(arr,n,n,vals)<<endl;
    cout<<dp2(arr,n)<<endl;
    return 0;
}