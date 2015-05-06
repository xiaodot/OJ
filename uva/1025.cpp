#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>

#define INF 1000000000

using namespace std;

int interval[51], hasTrain[51][201][2];
int dp[51][201];

int main(){
	freopen("../in.txt", "r", stdin);
	int m1, m2, n, T;
	int test = 1;
	while(true){
		memset(hasTrain, 0, sizeof(hasTrain));

		cin >> n >> T;
		if(!n) break;
		for(int i=1; i<n; i++){
			cin >> interval[i];
		}
		cin >> m1;
		int t;
		for(int i=1; i<=m1; i++){
			cin >> t;
			int t2 = t;
			hasTrain[1][t][0] = 1;
			for(int j=2; j<=n; j++){
				t2 += interval[j-1];
				hasTrain[j][t2][0] = 1;
			}
		}
		cin >> m2;
		for(int i=1; i<=m2; i++){
			cin >> t;
			int t2 = t;
			hasTrain[n][t][1] = 1;
			for(int j=n-1; j>=1; j--){
				t2 += interval[j];
				hasTrain[j][t2][1] = 1;
			}
		}
		
		for(int i=1; i<n; i++){
			dp[i][T] = INF;
		}
		dp[n][T] = 0;
		for(int j=T-1; j>=0; j--){
			for(int i=1; i<=n; i++){
				dp[i][j] = dp[i][j+1] + 1;
				if(hasTrain[i][j][0] && i<n && j+interval[i]<=T){
					dp[i][j] = min(dp[i][j], dp[i+1][j+interval[i]]);
				} 
				if(hasTrain[i][j][1] && i>1 && j+interval[i-1]<=T){
					dp[i][j] = min(dp[i][j], dp[i-1][j+interval[i-1]]);
				}
			}
		}	
		printf("Case Number %d: ", test++);
		if(dp[1][0] >= INF) cout << "impossible" << endl;
		else cout << dp[1][0] << endl;
	}
	
	return 0;
}