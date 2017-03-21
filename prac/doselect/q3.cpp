#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    int c1 = 0;
    int c2 = 0;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(s[i]=='A'){
                c1++;
            }else{
                c2++;
            }
        }else{
            if(s[i]=='C'){
                c1++;
            }else{
                c2++;
            }
        }
    }
    cout<<min(c1,c2)<<endl;
    return 0;
}