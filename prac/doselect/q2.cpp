#include <iostream>
#define MAXENTRY 2001
using namespace std;

int main(int argc, char const *argv[])
{
    int n,a;
    int arr[MAXENTRY]={0};
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        arr[a]++;
    }
    int ans = 0;
    for(int i=1;i<=2000;i++){
        int j = i;
        int c = 0;
        while(arr[j]){
            j++;
            c++;
        }
        if(c>ans){
            ans = c;
        }
    }
    cout<<ans<<endl;
    return 0;
}