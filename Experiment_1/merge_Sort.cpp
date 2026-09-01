// RIDWIK JAIN
// 25/DA/053
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int si, int mid, int ei)
{
    vector<int> helper;
    int i = si;
    int j = mid + 1;
    while (i <= mid && j <= ei)
    {
        if (arr[i] > arr[j])
        {
            helper.push_back(arr[j]);
            j++;
        }
        else
        {
            helper.push_back(arr[i]);
            i++;
        }
    }

    while (i <= mid)
    {
        helper.push_back(arr[i]);
        i++;
    }
    while (j <= ei)
    {
        helper.push_back(arr[j]);
        j++;
    }

    for (int idx = si, x = 0; idx <= ei; idx++, x++)
    {
        arr[idx] = helper[x];
    }
}

void mergesort_R(vector<int> &arr, int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = si + (ei - si) / 2;

    mergesort_R(arr, si, mid);
    mergesort_R(arr, mid + 1, ei);

    merge(arr, si, mid, ei);
}

void mergesort_I(vector<int> &arr,int si,int ei){
    int n=arr.size();

    for(int size=1;size<n;size*=2){
        for(int si=0;si<n-size;si+=2*size){
            int mid=si+size-1;

            int ei=min(si+2*size-1,n-1);

            merge(arr,si,mid,ei);
        }
    }
}

int main()
{
    vector<int> arr = {4, 7, 2, 1, 3, 9};
    // mergesort_R(arr,0,arr.size()-1);
    mergesort_I(arr,0,arr.size()-1);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}