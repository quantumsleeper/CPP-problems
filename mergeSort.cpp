#include <iostream>
using namespace std;

void merge(int arr[], int s, int mid, int e){
    //int n1 = mid-s+1;
    //int n2 = e-mid;
    int temp[10000];
    int i=s, j=mid+1, k=0; 

    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    if(i<=mid){
        while(i != mid+1){
            temp[k++]=arr[i++];
        }
    }
    if(j<=e){
        while(j != e+1){
            temp[k++]=arr[j++];
        }
    }
    for(int i=s, j=0; i<=e; i++, j++){
        arr[i]=temp[j];
    }
}

void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2 ;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, mid, e);
}


int main() {
    int n;
    int arr[n];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    mergeSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
