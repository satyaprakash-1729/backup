#include <iostream>

using namespace std;

int dp(string s1,string s2,int i,int j){
    if(i==0 || j==0){
        if(i) return i;
        else return j;
    }else if(s1[i]==s2[j]){
        return dp(s1,s2,i-1,j-1);
    }else if(s1[i]!=s2[j]){
        return 1+min(dp(s1,s2,i-1,j),min(dp(s1,s2,i-1,j-1),dp(s1,s2,i,j-1)));
    }
}

int main(int argc, char const *argv[])
{
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    int m = s1.length();
    int n = s2.length();
    cout<<dp(s1,s2,m,n)<<endl;
    return 0;
}