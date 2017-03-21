#include <iostream>
#include <algorithm>

using namespace std;

int dp_palin(string s,int n,int i,int j){
    if(i>j){
        return 0;
    }else if(i==j){
        return 1;
    }else{
        if(s[i]!=s[j]){
            return max(dp_palin(s,n,i+1,j),dp_palin(s,n,i,j-1));
        }else if(j==i+1){
            return 2;
        }else{
            return 2+dp_palin(s,n,i+1,j-1);
        }
    }
}

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    int n = s.length();
    cout<<dp_palin(s,n,0,n-1)<<endl;
    return 0;
}