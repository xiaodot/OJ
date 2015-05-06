#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

void exgcd(int a, int b, int &d, int &x, int &y){
	if(!b) {
		x = 1, y = 0, d = a;
	}
	else{
		exgcd(b, a%b, d, y, x),
		y -= (a/b)*x;
	}
}
int main(){
	freopen("../in.txt", "r", stdin);
	int m[3], rev[3], Mi[3];
	int a[3], s;
	int test = 1;
	while(true){
		for(int i=0; i<3; i++){
			cin >> a[i];
		}
		cin >> s;
		if(s==-1) break;

		m[0] = 23, m[1] = 28, m[2] = 33;
		int M = 1;
		for(int i=0; i<3; i++){
			M *= m[i];
		}
		for(int i=0; i<3; i++){
			Mi[i] = m[(i+1)%3]*m[(i+2)%3];
		}
		int x, y, d;
		for(int i=0; i<3; i++){
			exgcd(Mi[i], m[i], d, rev[i], y);
		}
		int res = 0;
		for(int i=0; i<3; i++){
			res += (Mi[i]*rev[i]*a[i] + M)%M;
		}	
		res %= M;
		res = res-s;
		if(res<=0) res = M + res;
		printf("Case %d: the next triple peak occurs in %d days.\n", test++, res);
	}
	
	return 0;
}