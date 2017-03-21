#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool comp(long a,long b){
    return a>b;
}
long decrementer(long);
long minOps(long arr[],int n){
    long min = arr[n-1];
    //cout<<min<<endl;
    long minOfAll = 100000000;
    long c;
    for(int i=0;i<5;i++){
        if(i==1 || i==2){
            c=1;
        }else if(i==0){
            c=0;
        }else{
            c=2;
        }
        for(int j=0;j<n-1;j++){
            long y = decrementer(max(arr[j]-(min-i),(long)0));
            c+=y;
            if(c<0) printf("%ld ",c );
            //cout<<arr[j]-(min-i)<<"-->"<<y<<endl;
        }
        if(c<minOfAll){
            minOfAll = c;
        }
    }
    return minOfAll;
}

long decrementer(long num){
    long c = 0;
    long rem = num%5;
    c = (num / 5);
    if(rem==4 || rem==3){
        c+=2;
    }else if(rem==2 || rem==1){
        c+=1;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    int t,n;
    scanf("%d",&t);
    //cin>>t;
    for(int z =0; z<t; z++){
        scanf("%d",&n);
        //cin>>n;
        long arr[n] = {-1};
        for(int i=0;i<n;i++){
            //cin>>arr[i];
            scanf("%ld",&arr[i]);
        }
        //cout<<n<<" - "<<arr[n-2]<<endl;
        sort(arr,arr+n,comp);
        //printf("%d\n",arr[n-1] );
        printf("%ld\n",minOps(arr,n));
    }
    return 0;
}