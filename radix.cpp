#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;
typedef struct node{
    int data;
    int sent;
    struct node* next;
} node;

typedef struct list{
    node* root;
    node* end;
}list;

node* createNode(int dat,int j){
    node* temp= (node *)malloc(sizeof(node));
    temp->data = dat;
    temp->next = NULL;
    temp->sent=j;
    return temp;
}

list* create(){
    list* temp = (list *)malloc(sizeof(list));
    temp->root=NULL;
    temp->end=NULL;
    return temp;
}

void insert(list* l,int dat,int j){
    if(l->root==NULL){
        node* temp=createNode(dat,j);
        l->root=temp;
        l->end=temp;
        return;
    }
    node* temp = createNode(dat,j);
    node* temp1 = l->end;
    temp1->next = temp;
    l->end = temp;
    return;
}

int extract(list** l,int j){
    if((*l)->root==NULL || (*l)->root->sent==j){
        return -1;
    }
    node* temp = (*l)->root;
    (*l)->root = (*l)->root->next;
    return temp->data;
}

void printl(list* B[]){
    printf("----------------------------\n");
    for(int i=0;i<10;i++){
        node* temp = B[i]->root;
        while(temp){
            printf("%d\n",temp->data );
            temp=temp->next;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n;
    srand(time(NULL));
    int arr[n];
    int dmax =0;
    for(int i=0;i<n;i++){
        arr[i]=rand()%341415;
        int fact = 10;
        int temp = arr[i];
        int dig = 1;
        while(temp/fact){
            fact*=10;
            dig++;
        }
        if(dig>dmax){
            dmax = dig;
        }
    }
    list* B[10];                                                                //Total: O(n*dmax)
    for(int i=0;i<10;i++){
        B[i]=create();
    }
    for(int i=0;i<n;i++){
        insert(B[arr[i]%10],arr[i],0);      //O(n)
    }
    int ar;
    for(int j=1;j<dmax;j++){                //O(dmax)
        for(int i=0;i<10;i++){                  //O(n)
            while((ar=extract(&B[i],j))!=-1){
            //printf("%d\n",ar );
                //printl(B);          
                int d = ((int)(ar/pow(10,j)))%10;
                insert(B[d],ar,j);
            }
        }
    }
    //printl(B);
    return 0;
}