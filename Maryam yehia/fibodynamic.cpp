#include <iostream>
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
//#include <algorithm>
#define ll long long
#define iose ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;
int fibonacci(int n) {
    if (n <= 1) return n;
    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}
int main(){
    iose;
   cout<< fibonacci(5);
    return 0;
}