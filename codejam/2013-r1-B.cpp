#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

int main(){
    freopen("B-small-practice.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    for(int test=1; test<=T; test++){
        int E, R, N, temp;
        int maxi = 0;s
        long long sum = 0;
        cin >> E >> R >> N;
        for(int i=0; i<N; i++){
            cin >> temp;
            maxi = max(maxi, temp);
            sum += temp;
        }
        sum -= maxi;
        if(R > E) sum = E*(sum+maxi);
        else
            sum = sum*R + E*maxi;
        printf("Case #%d: %lld\n", test, sum);
    }
    return 0;
}
