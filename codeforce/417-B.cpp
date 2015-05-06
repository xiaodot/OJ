#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;

int main(){
//    freopen("in.txt", "r", stdin);
    int lib[100001];
    memset(lib, -1, sizeof(lib));
    int T, x, k;
    scanf("%d", &T);
    for(int test=1; test<=T; test++){
        scanf("%d%d", &x, &k);
        if(lib[k]<x-1) {
            printf("NO");
            return 0;
        }
        else if(x == lib[k]+1) lib[k]++;
    }
    printf("YES");
    return 0;
}
