#include <iostream>
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
//#include <algorithm>
#define ll long long
#define iose ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
void files (){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void maxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void sortheap(int arr[],int n){
    maxHeap(arr,n);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{ iose ;
    int arr[6] = { 1,0,4,3,6,9};
    int n = 6;
    maxHeap(arr, n);
    printArray(arr, n);
    sortheap(arr,n);
    printArray(arr, n);

    return 0;
}