#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int n1, int n2)
{
    if (n2 != 0)
       return gcd(n2, n1 % n2);
    else 
       return n1;
}

int proc(int s[], int n,int i,int count,int gcdres){
    if(gcdres==1 || i == n){
        return count-1;
    }
    return max(proc(s,n,i+1,count+1,gcd(gcdres,s[i+1])),proc(s,n,i+1,count,gcdres));
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int ans[n][100000];
    
    return 0;
}