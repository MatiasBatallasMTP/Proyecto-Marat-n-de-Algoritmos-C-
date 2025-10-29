#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i){
    int largest=i;
    int l=2*i+1, r=2*i+2;
    if(l<n && arr[l]>arr[largest]) largest=l;
    if(r<n && arr[r]>arr[largest]) largest=r;
    if(largest!=i){
        swap(arr[i], arr[largest]);
        heapify(arr,n,largest);
    }
}

void buildHeap(vector<int>& arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
}

int main(){
    vector<int> arr={4,10,3,5,1};
    buildHeap(arr);
    for(int x:arr) cout<<x<<" "; cout<<endl;
}
