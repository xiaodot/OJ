#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
//    freopen("in.txt", "r", stdin);
    int T;
    int x, y, sign, lp, rp;
    char c, ans;
    scanf("%d", &T);
    getchar();
    lp = -2E9, rp = 2E9;
    for(int i=0; i<T; i++){
        sign = 0;
        while((c = getchar()) != ' '){
            if(c == '<') sign += 0;
            if(c == '=') sign += 1;
            if(c == '>') sign += 2;
        }
        scanf("%d %c", &x, &ans);
        getchar();
        if(ans == 'Y'){
            if(sign == 0) rp = min(rp, x - 1);
            if(sign == 1) rp = min(rp, x);
            if(sign == 2) lp = max(lp, x + 1);
            if(sign == 3) lp = max(lp, x);
        }
        else{
            if(sign == 0) lp = max(lp, x);
            if(sign == 1) lp = max(lp, x + 1);
            if(sign == 2) rp = min(rp, x);
            if(sign == 3) rp = min(rp, x -1);
        }
        if(lp > rp) {
            printf("Impossible\n");
            break;
        }
//        printf("%d %d %c %d\n", sign, x, ans);
    }
    if(lp <= rp) printf("%d\n", lp);
    return 0;
}
