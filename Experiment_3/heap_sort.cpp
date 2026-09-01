// RIDWIK JAIN
// 25/DA/053
#include <iostream>
#include <vector>
using namespace std;

void heapify(int i,vector<int> &arr,int n){
    int left=2*i+1;
    int right=2*i+2;
    int maxi=i;

    if(left<n && arr[left]>arr[maxi]){
        maxi=left;
    }

    if(right<n && arr[right]> arr[maxi]){
        maxi=right;
    }

    if(maxi!=i){
        swap(arr[i],arr[maxi]);
        heapify(maxi,arr,n);
    }
}

void heapSort(vector<int>&arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(i,arr,n);
    }

    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(0,arr,i);
    }
}

int main(){
    vector<int> arr={0,2,4,1,2,3,9};
    heapSort(arr);
    cout<<"Sorted Array is ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}