#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count[4]={0,0,0,0}; //A T G C
    int maxs = 0;
    if(n%4!=0){
        cout<<"==="<<endl;
        return 0;
    }
    int ques = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='?'){
            ques++;
            continue;
        }
        if(s[i]=='A')
            count[0]++;
        else if(s[i]=='T')
            count[1]++;
        else if(s[i]=='G')
            count[2]++;
        else
            count[3]++;
    }
    maxs = max(count[0],max(count[1],max(count[2],count[3])));
    int rho = ques - (4*maxs-(count[0]+count[1]+count[2]+count[3]));
    if(rho<0){
        cout<<"==="<<endl;
        return 0;
    }
    string ans;
    char seq[4] = {'A','T','G','C'};
    for(int i=0;i<n;i++){
        if(s[i]!='?'){
            ans.insert(i,1,s[i]);
        }else{
            if(count[0]){
                ans.insert(i,1,'A');
                count[0]--;
            }else if(count[1]){
                ans.insert(i,1,'T');
                count[1]--;
            }else if(count[2]){
                ans.insert(i,1,'G');
                count[2]--;
            }else if(count[3]){
                ans.insert(i,1,'C');
                count[3]--;
            }else{
                int r = 0;
                while(i<n){
                    if(s[i]=='?'){
                        ans.insert(i,1,seq[r%4]);
                        r++;
                    }
                    i++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}