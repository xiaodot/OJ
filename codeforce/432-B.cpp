#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int x[100001], y[100000];
int cntx[100000], cnty[100000];
int main(){
//    freopen("../in.txt", "r", stdin);
    int n;
    memset(x, 0, sizeof(x));
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp >> y[i];
        x[temp]++;
    }
    memset(cntx, 0, sizeof(cntx));
    memset(cnty, 0, sizeof(cnty));
    for(int i=0; i<n; i++){
       int temp = x[y[i]];
       cntx[i] = n - 1 + temp;
       cnty[i] = n - 1 - temp;
    }
    for(int i=0; i<n; i++){
        cout << cntx[i] << ' ' << cnty[i] << endl;
    }
    return 0;
}

