
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

long long ireverse(long long i){
    long long res = 0;
    if(i%10 == 0) return -1;
    while(i){
        res = res*10 + i%10;
        i /= 10;
    }
    return res;
}
long long dp[1005];

long long data[16];
int main(){
    freopen("in.txt", "r", stdin);
//    freopen("out-bigdata-A.txt", "w", stdout);

    int T;
    cin >> T;
    data[1] = 9;
    data[2] = 28;

    for(int i=3; i<16; i++){
        data[i] = data[i-1] + 99 + pow(10, i-2);
    }

    memset(dp, 0, sizeof(dp));

    for(int i=1; i<1005; i++){
        dp[i] = dp[i-1] + 1;
        int ire = ireverse(i);

        if(ire != -1 && ire < i) {
            if(dp[i] > dp[ire] + 1) {
                dp[i] = dp[ire] + 1;
            }
        }

    }

    for(int test=1; test<=T; test++){
        long long N;
        cin >> N;
        long long res = 0;

        long long digit = 0;
        long long tmp = 1;
        while(N/tmp){
            digit++;
            tmp *= 10;
        }


//        cout << tmp << " " << digit << endl;

        if(digit <= 3){
            res = dp[N];
        }
        else {

            long long first, second;
            for(int i=0; i<digit/2; i++){

            }
            if(N/(tmp/10) != 1 || N/(tmp/100)%10 != 0){
                while(true){
                    if(N%10 == 1 && (N/10)%10 == 0) break;
                    N--;
                    res++;
                }
    //            long long ten = N%10 + ((N/10)%10)*10;
    //            res += ten - 1;
    //            N -= ten - 1;

                N = ireverse(N);
                res++;
            }


            tmp = tmp/10 - 1;
            res += N - tmp;

            res += data[digit-1];

        }
        printf("Case #%d: %d\n", test, res);


    }

//    for(int i=1; i<16; i++){
//            cout << i << " " << data[i] << endl;
//        }

    return 0;
}
