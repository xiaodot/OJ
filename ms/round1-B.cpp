#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int test=1; test<=T; test++){
        int n;
        scanf("%d", &n);
        if(n == 1 || n == 2){
            printf("Case %d: no solution\n", test);
        }
        else {
            printf("Case %d: %d %d 1\n", test, 2*(n-1), n-1);
        }
    }
    return 0;
}
