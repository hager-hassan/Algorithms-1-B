#include <iostream>
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
//#include <algorithm>
#define ll long long
#define iose ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
int binarysearch( int v[] ,int val,int low,int high){
    int mid=low+((high-low)/2);
    if (high<low) {return -1; }
    if (v[mid]==val){return mid;}
    if (val<v[mid])return binarysearch(v,val,low,mid-1);
    if (val>v[mid])return binarysearch(v,val,mid+1,high);

}
int main(){iose;
    int arr[8]={9,4,73,10,6,7,2,1};
//    vector<int>v{};
    sort(arr,arr+8);
//    {1,2,4,6,9,10,73}
   cout<< binarysearch(arr,5,0,7)<<"\n";
   cout<< binarysearch(arr,4,0,7);


    return 0;
}
