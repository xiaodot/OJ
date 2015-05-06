#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

int dp[1000010];
int P(int k, int n){
    int qt = n/k;
    int re = n%k;
    qt = qt%2;
    int res = 0;
    if(qt == 1){
        res = dp[k-1];
    }
    res = res ^ dp[re];
    return res;
}
int main(){
    freopen("../in.txt", "r", stdin);
    int n, p, res=0;
    dp[0] = 0;
    for(int i=1; i<1000010; i++){
        dp[i] = dp[i-1]^i;
    }
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> p;
        res = res^p;
    }
    for(int i=1; i<=n; i++){
        res = res^P(i, n);
    }
    cout << res << endl;
    return 0;
}
