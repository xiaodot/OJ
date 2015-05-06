#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

int main(){
    freopen("A-large-practice.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    for(int i=1; i<=T; i++){
        long long r, t, res = 0;
        cin >> r >> t;
        long long left = 1, right = t;
        while(right - left > 1){
            res = (left+right)/2;
            if(2*res + 2*r - 1 > (double)t /res) right = res;
            else left = res;
        }
        printf("Case #%d: %d\n", i, left);
    }
    return 0;
}
