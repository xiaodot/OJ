#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;
const int mod = 100007;

int dp[1010][1010];

int main(){
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int test=1; test<=T; test++){
        int res = 0;
        string str;
        cin >> str;
        memset(dp, 0, sizeof(dp));
        int len = str.length();

        for(int i=0; i<len; i++) dp[i][0] = 1;
        for(int i=0; i+1<len; i++){
            if(str[i] == str[i+1]) dp[i][1] = 3;
            else dp[i][1] = 2;
        }
        for(int i=2; i<len; i++){
            for(int j=0; j+i<len; j++){
                if(str[j] == str[j+i]) dp[j][i] = (1 + dp[j][i-1] + dp[j+1][i-1])%mod;
                else dp[j][i] = (dp[j][i-1] + dp[j+1][i-1] - dp[j+1][i-2])%mod;
            }
        }
        res = dp[0][len-1];
        printf("Case #%d: %d\n", test, res);
    }
    return 0;
}
