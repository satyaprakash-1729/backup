#include <iostream>
#include <algorithm>
#define modulo 1000000007
#define ull unsigned long long
using namespace std;

bool comp(ull a,ull b){
    return a>b;
}

int main(int argc, char const *argv[])
{
    int q;
    cin>>q;
    for(int k=0;k<q;k++){
        int m,n;
        cin>>m>>n;
        ull Cy[m-1];
        for(int i=0;i<m-1;i++){
            cin>>Cy[i];
        }
        ull Cx[n-1];
        for(int i=0;i<n-1;i++){
            cin>>Cx[i];
        }
        ull c=0;
        int x=1;
        int y=1;
        sort(Cy,Cy+m-1,comp);
        sort(Cx,Cx+n-1,comp);
        while(y < m || x < n){
            if(x==n){
                while(y<m){
                    c=(c+Cy[y-1]*x);
                    y++;
                }
            }else if(y==m){
                while(x<n){
                    c=(c+Cx[x-1]*y);
                    x++;
                }
            }else{
                if(Cx[x-1] > Cy[y-1]){
                    c=(c+Cx[x-1]*(y));
                    x++;
                }else{
                    c=(c+Cy[y-1]*x);
                    y++;
                }
            }
        }
        cout<<c%modulo<<endl;
    }
    return 0;
}