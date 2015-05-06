#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
//    freopen("in.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    if(n*(n-1)/2 < n*k){
        printf("-1");
        return 0;
    }
    int total = n*k;
    printf("%d\n", total);
    for(int i=0; i<n; i++){
        for(int j=i; j<i+k; j++){
            printf("%d %d\n", i+1, (j+1)%n+1);
        }
    }
    return 0;
}
