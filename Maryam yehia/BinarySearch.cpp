#include <iostream>
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
//#include <algorithm>
#define ll long long
#define iose ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
bool binarysearch( vector<int>v ,int val,int low,int high){
    int mid=low+((high-low)/2);
    if (high<low) {cout<<"Not Found!"<<"\n"; return false; }
    if (v[mid]==val){cout<<"Index: "<<mid<<"\n";return true;}
    if (val<v[mid])return binarysearch(v,val,low,mid-1);
    if (val>v[mid])return binarysearch(v,val,mid+1,high);

}
int main(){iose;
    vector<int>v{9,4,73,10,6,7,2,1};
    std::sort(v.begin(), v.end());
//    {1,2,4,6,9,10,73}
    binarysearch(v,5,0,v.size()-1);
    binarysearch(v,4,0,v.size()-1);


    return 0;
}