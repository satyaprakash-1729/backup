#include <iostream>
#include <vector>
using namespace std;

int recursive(int, vector<vector<int>>,bool[]);

int totalMatching(int input1, char* input2[]){
    vector<vector<int>> list;
    for(int x=0;x<input1;x++){
        string str(input2[x]);
        int last = 0;
        vector<int> wom;
        for(int i = 0; i<str.length();i++){
            if(str[i]=='W'){
                if(last!=0){
                    string temp="";
                    for(int j =last+1;j<=i-2;j++){
                        temp+=str[j];
                    }
                    wom.push_back(stoi(temp)-1);
                }
                last = i;
            }
        }
        if(last!=0){
            string temp="";
            for(int j =last+1;j<str.length();j++){
                temp+=str[j];
            }
            wom.push_back(stoi(temp)-1);
        }
        if(wom.size()==0){
            return 0;
        }
        list.push_back(wom);
    }
    bool done[input1] = {0};
    int ans = recursive(input1, list, done);
    if(ans<0){
        ans = 0;
    }
    return ans;
}

int recursive(int n, vector<vector<int>> l,bool done[]){
    if(n==0){
        return 1;
    }
    int r = 0;
    bool flag = 0;
    for(int i=0;i<l[n-1].size();i++){
        if(!done[l[n-1][i]]){
            flag =1;
            done[l[n-1][i]]=1;
            int temp = recursive(n-1,l,done);
            r+=temp;
        }
    }
    return r;
}

int main(int argc, char const *argv[])
{
    char* arr[2];
    char* temp1 = "M1#W1";//#W1#W2";
    char* temp2 = "M2#W2#W3";
    *(arr) = temp1;
    *(arr+1) = temp2;
    int a = totalMatching(2,arr);
    cout<<a<<endl;
    return 0;
}