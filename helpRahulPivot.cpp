// Binary Serach on rotated array
#include<iostream>
using namespace std; 

int find_key(int* arr, int n, int key){
    int start = 0; 
    int end = n-1;
    while(start <= end){
        int mid = (start + end)/2;
        if(arr[mid] == key){
            return mid;
        }
        if(arr[start] <= arr[mid]){
            // 2 cases : element lies either to the left or right of mid
            if(key >= arr[start] && key <= arr[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        else{
            if(key >= arr[mid] && key <= arr[end]){
                start = mid+1;
            }
            else{
                end = mid-1; 
            }
        }
    }
    return -1; 

}

int main(){
    int n, key; 
    cin >> n; 
    int a[1000]; 

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> key; 
    cout << find_key(a, n, key);
    return 0; 

}
