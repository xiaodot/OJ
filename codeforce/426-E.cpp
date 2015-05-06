#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    freopen("../in.txt", "r", stdin);
    int n, m, s, e;
    int a[100001], b[100001], c[100001];
    cin >> n >> m >> s >> e;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=m; i++){
        cin >> b[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i] == b[j]) c[i] = j;
        }
    }
    return 0;
}
