#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node* next;
} node;

node* createNode(int dat){
    node* temp = (node *)malloc(sizeof(node));
    temp->data = dat;
    temp->next = NULL;
    return temp;
}

typedef struct list{
    node* root;
    node* end;
} list;

list* create(){
    list* temp = (list *)malloc(sizeof(list));
    temp->root=NULL;
    temp->end=NULL;
    return temp;
}

void insert(list* l,int x){
    node* temp = l->end;
    if(temp==NULL){
        node* temp1 = createNode(x);
        l->root=temp1;
        l->end=temp1;
        return;
    }
    temp->next = createNode(x);
    l->end = temp->next;
    return;
}

void printl(list* arr[],int n,int r){
    int i;
    node* temp;
    int sent = 0;
    for(i=0;i<n;i++){
        if(temp=(arr[i]->root)){
            while(temp){
                sent++;
                printf("%d\n",temp->data);
                temp = temp->next;
            }
        }
        if(sent>r){
            break;
        }
    }
    return;
}

void radix(int arr[],int n,int k,int r){
    list* B[10];
    int i,j;
    for(i=0;i<k;i++){
        for(j=0;j<10;j++){
            B[j]=create();
        }
        for(j=0;j<n;j++){
            //if((arr[j]/((int)pow(10.0,i)))){
                int d = (arr[j]/((int)pow(10.0,i)))%10;
                printf("--%d\n",d);
                insert(B[d],arr[j]);
            //}
        }
    }
    //printl(B,10,r);
    return;
}

int main(int argc, char const *argv[])
{
    int i,n,r;
    srand(time(NULL));
    printf("Enter n:  ");
    scanf("%d",&n);
    int arr[n];
    int maxd=0;
    int max=0;
    for(i=0;i<n;i++){
        arr[i] = rand()%1000000;
        printf("%d ",arr[i]);
        if(max<arr[i]){
            max = arr[i];
        }
    }
    while(max){
        maxd++;
        max=max/10;
    }
    printf("\nEnter limit:\n");
    scanf("%d",&r);
    radix(arr,n,maxd,r);
    return 0;
}