#include <iostream>
#include <vector>
using namespace std;

int maxsub(string s,string t){
    int m = s.length();
    int n = t.length();
    int ansmax = 0;
    int row[m+1]={0};
    int rown[m+1] = {0};
    for(int i = 1;i<n+1;i++){
        for(int j =1;j<m+1;j++){
            if(t[i-1]==s[j-1]){
                rown[j] = row[j-1]+1;
            }else{
                rown[j] = 0;
            }
            if(rown[j]>ansmax){
                ansmax = rown[j];
            }
        }
        for(int j=1;j<m+1;j++){
            row[j]=rown[j];
        }
    }
    return ansmax;
}

int main(int argc, char const *argv[])
{
    int n,q;
    cin>>n>>q;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<maxsub(arr[a],arr[b])<<endl;
    }
    return 0;
}