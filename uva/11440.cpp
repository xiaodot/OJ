#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>


#define MAXSIZE 10000000
#define mod 100000007
using namespace std;

long long phifact[MAXSIZE+1];  // the total number of prime numbers with M! which is no more than M!
bool prim[MAXSIZE+1]; // the prime number list

int main(){
	freopen("../in.txt", "r", stdin);

    // calculate the prime number list
	memset(prim, 0, sizeof(prim));
	for(int i=2; i<=sqrt(MAXSIZE); i++) if(!prim[i]){
		for(int j=i*i; j<=MAXSIZE; j+=i){
			prim[j] = 1;
		}
	}
	//note the special case where phifact[1]=1
	phifact[1] = phifact[2] = 1;
	for(int i=3; i<=MAXSIZE; i++){
		phifact[i] = phifact[i-1]*(!prim[i]? (i-1): i) % mod;
	}
	int m, n;
	while(cin >> n >> m){
        if(!n && !m) break;
		long long ans = phifact[m];
		for(int k = m+1; k<=n; k++){
			ans = ans*k % mod;
		}
		cout << (ans-1+mod)%mod << endl;  // "ans - 1" is because we count the number from 2 rather than 1
	}

	return 0;
}
