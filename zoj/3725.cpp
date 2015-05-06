#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 1000000007;
int dp[100010];

int main(){
	freopen("../in.txt", "r", stdin);
	int n, m;
	while(cin >> n >> m){
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i=1; i<=n; i++){
			// notice the priority of the operation % 
			// don't forget the blankets before %
			dp[i] = ((long long)2*dp[i-1]) % mod;
			if(i-m-1>=0){
				dp[i] = (dp[i] - dp[i-m-1] + mod) % mod;
			}
			if(i==m) dp[i] = (dp[i] - 1 + mod) % mod;
		}
		int res = 1;
		int j = n;
		while(j){
			res = ((long long)res*2 ) % mod;
			j--;
		}
		
		res = (res - dp[n] + mod) % mod;
		//res -= dp[n];
		cout << res << endl;
	}
	return 0;
}