#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int main(){
    freopen("../in.txt", "r", stdin);
    int n, m, k;
    int a[20001][11];
    int res[20001], chat[11];
    memset(res, 0, sizeof(res));
    memset(chat, 0, sizeof(chat));
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=k; i++){
        int p1, p2;
        cin >> p1 >> p2;
        res[p1]--;
        chat[p2]++;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            res[i] += a[i][j]*chat[j];
        }
        cout << res[i] << " ";
    }
    return 0;
}

