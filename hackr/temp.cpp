#include <iostream>
#include <algorithm>

using namespace std;

typedef struct node{
    int data;
    int pos;
} node;

node* create(){
    node* temp = (node *)malloc(sizeof(node));
    temp->data=0;
    temp->pos=0;
    return temp;
}

bool comp(node* a,node* b){
    return (a->data < b->data);
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    node* fin[n];
    int t,d;
    for(int i=0;i<n;i++){
        fin[i]=create();
        cin>>t>>d;
        fin[i]->data=t+d;
        fin[i]->pos=i;
    }
    sort(fin,fin+n,comp);
    for(int i=0;i<n;i++){
        cout<<(fin[i]->pos)+1<<" ";
    }
    cout<<endl;
    return 0;
}