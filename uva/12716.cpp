#include <iostream>
#include <stdio.h>
#include <cmath>

#define MaxN 30000001

using namespace std;

int gcd(int a, int b){
    return b==0? a: gcd(b, a%b);
}

int sol[MaxN];
int calc(int n){
    if(n==1) return 0;
    int res = calc(n-1);
    if(n%2==0 && ) return calc(n-1)
}

int main(){
    freopen("../in.txt", "r", stdin);
    int a, b, c, n, res, T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        res = 0;
        cin >> n;
        for(c=1; c<=n/2; c++){
            for(a=2*c; a<=n; a=a+c){
                b = a^c;
                if(c==a-b) res++;
            }
        }

        printf("Case %d: %d\n", test, res);
    }
    return 0;
}
