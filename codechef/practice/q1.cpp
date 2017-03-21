#include <iostream>

using namespace std;

typedef struct node{
    int data;
    struct node* next;
} node;

typedef struct list{
    node* root;
    int indegree;
    int outdegree;
}list;

node* createNode(int dat){
    node* temp= (node *)malloc(sizeof(node));
    temp->data = dat;
    temp->next = NULL;
    return temp;
}

list* create(){
    list* temp = (list *)malloc(sizeof(list));
    temp->root=NULL;
    temp->indegree = 0;
    temp->outdegree = 0;
    return temp;
}

void insert(list* l,int dat){
    if(l->root==NULL){
        l->root=createNode(dat);
        return;
    }
    node* temp = l->root;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = createNode(dat);
    return;
}

int main(int argc, char const *argv[])
{
    int a,b,n,e;
    cin>>n>>e;
    list* adj[n+1];
    for(int i=1;i<=n;i++){
        adj[i]=create();
    }
    for(int i=0;i<e;i++){
        cin>>a>>b;
        insert(adj[a],b);
        adj[a]->indegree++;
        adj[b]->outdegree++;
    }
    for(int i=1;i<=n;i++){
        if(adj[i]->indegree > adj[i]->outdegree){
            
        }
    }
    return 0;
}