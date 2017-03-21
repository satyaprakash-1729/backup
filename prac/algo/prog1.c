#include <stdio.h>
#include <stdlib.h>

int findMaxUniModal(int arr[],int n,int start,int end){
    if(end-start>2){
        int mid = (start+end)/2;
        if(arr[mid]<arr[mid+1]){
            return findMaxUniModal(arr,n,mid+1,end);
        }else{
            return findMaxUniModal(arr,n,start,mid);
        }
    }else{
        if(end-start==1){
            return arr[start];
        }else if(end-start==2){
            return arr[start]>arr[start+1]?arr[start]:arr[start+1];
        }
    }
}

int main(int argc, char const *argv[])
{
    int i,n;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d\n",findMaxUniModal(arr,n,0,n));
    return 0;
}