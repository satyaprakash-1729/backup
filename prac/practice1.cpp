#include <iostream>
#include <mylib1729.h>

using namespace std;

void insertionSort(int arr[],int low,int high){
    int temp,j;
    int size = high-low+1;
    if(size<=1){
        return;
    }
    for(int i=low + 1;i<=high;i++){
        temp = arr[i];
        int j = i-1;
        while(arr[j]>temp && j>=low){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    return;
}

int partition(int arr[],int low,int high,int k){
    int i,j;
    i = low;
    j = high;
    while(i<=j){
        while(i<=j && arr[i]<=k){
            i++;
        }
        while(i<=j && arr[j]>k){
            j--;
        }
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return j;
}

int findkth(int arr[],int low,int high,int k){
    //cout<<"n:"<<n<<endl;
    int num;
    int size = high-low+1;
    //if(size<=10){
    //    insertionSort(arr,low,high);
    //    return arr[k-1];
    //}
    if(size%5){
        num = size/5+1;
    }else{
        num = size/5;
    }
    int medians[num];
    for(int i=low;i<low+(size-(size%5));i+=5){
        insertionSort(arr,i,i+4);
    }
    if(size%5){
        insertionSort(arr,low+size-(size%5),low+size-1);
    }
    if(size%5==0){
        for(int i=0;i<num;i++){
            medians[i] = arr[low + 5*i+2];
        }
    }else{
        for(int i=0;i<num-1;i++){
            medians[i] = arr[low + 5*i+2];
        }
        medians[num-1] = arr[low+size-(size%5) + (size%5)/2];
    }
    int medOfmed = findkth(medians,0,num-1,num/2+1);
    int r = partition(arr,low,high,medOfmed);
    //cout<<"-->"<<medOfmed<<endl;
    //for(int i=0;i<n;i++){
    //    cout<<arr[i]<<" ";
    //}
    //cout<<endl;
    if(r==k-1){
        //cout<<"das"<<medOfmed<<endl;
        return medOfmed;
    }else if(k-1 < r){
        return findkth(arr, low, r - 1, k);
    }else{
        return findkth(arr, r + 1, high, k - r - 1);
    }
}

int main(int argc, char const *argv[])
{
    int n,k;
    cout<<"Enter number of entries: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter numbers"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Which number do u want to find?"<<endl;
    cin>>k;
    int kth = findkth(arr,0,n-1,k);
    cout<<k<<"th number by blum: "<<kth<<endl;
    insertionSort(arr,0,n-1);
    cout<<k<<"th number by sort: "<<arr[k-1]<<endl;
    return 0;
}