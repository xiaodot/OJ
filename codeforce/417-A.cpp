#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
//    freopen("in.txt", "r", stdin);
    int c, d, n, m, k;
    scanf("%d%d%d%d%d", &c, &d, &n, &m, &k);
    int remain = n*m - k;
    if(remain < 0){
        printf("%d", 0);
        return 0;
    }
    int x = 0, y = 0;
    int res = remain*(c+d);
    for(; x<=m-k/n+1; x++){
        y = max(0, remain - n*x);
        res = min(res, c*x+d*y);
    }
    printf("%d", res);
    return 0;
}
