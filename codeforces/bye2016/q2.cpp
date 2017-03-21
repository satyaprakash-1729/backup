#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,t;
    cin>>n;
    int y = 20000;
    string dir;
    bool flag = false;
    for(int i=0;i<n;i++){
        cin>>t>>dir;
        if(y == 20000 && dir != "South"){
            flag = true;
        }else if(y == 0 && dir != "North"){
            flag = true;
        }
        if(dir == "North"){
            if(y+t > 20000){
                flag = true;
            }else{
                y+=t;
            }
        }
        if(dir == "South"){
            if(y-t < 0){
                flag = true;
            }else{
                y-=t;
            }
        }

    //cout<<"-->"<<y<<endl;           
    }
    if(!flag && y==20000){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}