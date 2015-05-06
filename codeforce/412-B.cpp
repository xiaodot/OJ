#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int a[110];
bool comp(int i, int j){
    return i>j;
}
int main(){
    freopen("../in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n, comp);
    cout << a[k-1];
    return 0;
}
