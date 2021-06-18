#include<iostream>
#include<vector>
using namespace std; 

class Heap{
    vector<int>v; 
    bool minHeap; // If true, we'll build a min heap. Else, a max heap

    bool compare(int a, int b){
        if(minHeap){
            return a < b;
        }
        else{
            return a > b;
        }
    }

    void heapify(int parent){
        // Indices of left and right child
        int left = 2*parent; 
        int right = 2*parent + 1;
        int min_idx = parent; // To track min (or max) element up till now
        int last = v.size()-1; 

        // Swapping can be done only if left/right child exist in the first place 
        // To check whether they exist, we'll see if indices of both the left and right child
        // is less than the last index of the vector
        if(left <= last && compare(v[left], v[parent])){
            min_idx = left;
        }
        if(right <= last && compare(v[right], v[min_idx])){
            min_idx = right; 
        }
        if(min_idx != parent){
            swap(v[parent], v[min_idx]); 
            heapify(min_idx); 
        }

    }

public:

    Heap(int default_size=10, bool type=true){
        v.reserve(default_size);
        v.push_back(-1); // blocking the 0th index with -1
        minHeap = type;
    }

    void push(int data){
        v.push_back(data);
        int idx = v.size()-1 ; 
        int parent_idx = idx/2 ;

        // Readjust the tree to maintain heap property
        // Keep pushing the element to the top, till you either reach the root, or have to 
        // stop midway 'cuz your node has become > (or < ) its parent.
        while(idx > 1 && compare(v[idx], v[parent_idx])){
            swap(v[idx], v[parent_idx]);
            idx = parent_idx; 
            parent_idx = idx/2 ;
        }
    }

    int top(){
        return v[1];
    }

    void pop(){
        int last_idx = v.size() - 1; 
        swap(v[1], v[last_idx]); 
        v.pop_back();
        heapify(1); // Call heapify with the index you want to start heapification with 
    }

    bool isEmpty(){
        return v.size() == 1; 
    } 

};


int main(){
    Heap h; 
    int n; 
    cin >> n; 

    for (int i = 0; i < n; i++){
        int d; 
        cin >> d; 
        h.push(d); 
    }
    while(!h.isEmpty()){
        cout << h.top() << " ";
        h.pop(); 
    }

    return 0; 
}