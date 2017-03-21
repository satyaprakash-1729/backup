#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int t,n;
    cin>>t;
    for(int z=0;z<t;z++){
        cin>>n;
        int xenny[n];
        int yana[n];
        int xenny1st=0;
        int yana1st=0;
        for(int i=0;i<n;i++){
            cin>>xenny[i];
            if(i%2){
                yana1st+=xenny[i];
            }else{
                xenny1st+=xenny[i];
            }
        }
        for(int i=0;i<n;i++){
            cin>>yana[i];
            if(i%2){
                xenny1st+=yana[i];
            }else{
                yana1st+=yana[i];
            }
        }
        cout<<min(xenny1st,yana1st)<<endl;
    }
    return 0;
}