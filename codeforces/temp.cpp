#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n>>k;
    int neg=0;
    int temp[n];
    bool negis[n]={0};
    vector<int> nonzer;
    for(int i=0;i<n;i++){
        cin>>temp[i];
        if(temp[i]<0){
            neg++;
            negis[i]=1;
            if(!nonzer.size() || nonzer[nonzer.size()-1]!=0){
                nonzer.push_back(0);
            }
        }else{
            if(i!=0 && nonzer.size()){
                nonzer[nonzer.size()-1]++;
            }
        }
    }
    if(neg>k){
        cout<<-1<<endl;
        return 0;
    }
    if(neg==0){
        cout<<0<<endl;
        return 0;
    }
    if(neg==k){
        int ans;
        if(negis[0]){
            ans=1;
        }else{
            ans=0;
        }
        for(int i=1;i<n;i++){
            if(negis[i-1]==!negis[i]){
                ans++;
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    bool flag=0;
    int ans;
    if(temp[n-1]<0){
        flag=1;
    }
    k-=neg;
    if(negis[0]){
        ans=1;
    }else{
        ans=0;
    }
    for(int i=1;i<n;i++){
        if(negis[i-1]==!negis[i]){
            ans++;
        }
    }
    int last = nonzer[nonzer.size()-1];
    sort(nonzer.begin(),nonzer.end());
    for(int i=0;i<nonzer.size();i++){
        int r = nonzer[i];
        if(k-r>=0){
            k-=r;
            if(!flag && r==last && (i==nonzer.size()-1 || nonzer[i+1]!=last)){
                ans-=1;
                continue;
            }
            ans-=2;
        }else{
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}