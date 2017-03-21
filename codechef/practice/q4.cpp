#include <iostream>

using namespace std;

int maxchunk(string s){
    int n = s.length();
    int maxa=0;
    int temp=0;
    char sent='i';
    for(int i=0;i<n;i++){
        if(s[i]!=sent){
            if(maxa<temp){
                maxa = temp;
            }
            sent = s[i];
            temp=1;
        }else{
            temp++;
        }
        if(i==n-1){
            if(temp>maxa){
                maxa = temp;
            }
        }
    }
    return maxa;
}

int dp(string S, int n, int k){
    if(k==0 || n<0){
        return maxchunk(S);
    }
    if(S[n-1]=='0'){
        int r = n-1;
        while(S[r]=='0'){
            r--;
        }
        if(S[n]=='0'){
            string temp = S;
            temp[n]='1';
            return min(max(n-r,dp(S,n-1,k)),dp(temp,n-1,k-1));
        }else{
            string temp = S;
            temp[n]='0';
            return min(max(1,dp(S,n-1,k)),dp(temp,n-1,k-1));
        }
    }else{
        int r = n-1;
        while(S[r]=='1'){
            r--;
        }
        if(S[n]=='1'){
            string temp = S;
            temp[n]='1';
            return min(max(n-r,dp(S,n-1,k)),dp(temp,n-1,k-1));
        }else{
            string temp = S;
            temp[n]='1';
            return min(max(1,dp(S,n-1,k)),dp(temp,n-1,k-1));
        }
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    for(int z=0;z<t;z++){
        int n,k;
        cin>>n>>k;
        string inp;
        cin>>inp;
        //cout<<maxchunk(inp)<<endl;
        cout<<dp(inp,n-1,k)<<endl;
    }
    return 0;
}