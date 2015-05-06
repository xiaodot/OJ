#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1E9 + 7;
int ans[100010];

int main(){
	freopen("../in.txt", "r", stdin);
	int t, k, a, b;
	cin >> t >> k;
	memset(ans, 0, sizeof(ans));

	for(int i=0; i<=1E5; i++){
		if(i<k) ans[i] = 1;
		else{
			ans[i] = (ans[i-1] + ans[i-k]) % MOD;
		}
	}
	for(int i=1; i<=1E5; i++){
		ans[i] = (ans[i] + ans[i-1]) % MOD;
	}

	for(int test = 0; test < t; test++){
		cin >> a >> b;
		cout << ((MOD + ans[b] - ans[a-1]) % MOD) << endl;
	}
	return 0;
}
