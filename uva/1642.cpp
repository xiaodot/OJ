#include <iostream>
#include <stdio.h>
#include <map>
#include <cstring>

using namespace std;

typedef long long LL;

LL dat[100005];
LL gcd(LL a, LL b){
	return !b ? a : gcd(b, a%b);
}

// we observe that, for a given j, the gcd value of [i, j] will not increase with decreasing i.

// use myMap to record all different values of gcd() corresponding to the interval [i, j].
// if [i1,j] and [i2, j] have the same value of gcd(), we only need to record the situation where i is smaller.
// In such situation, the length of the intervel is greater, consequently greater output.
map<LL, LL> myMap;
map<LL, LL> ::iterator it, it2;

int main(){
	freopen("../in.txt", "r", stdin);
	int T;
	cin >> T;
	for(int test=1; test<=T; test++){
		int n;
		LL res = 0;
		cin >> n;
		memset(dat, 0, sizeof(dat));
		for(int i=1; i<=n; i++){
			cin >> dat[i];
			res = max(res, dat[i]);
		}

		myMap.clear();

		int left = 1, right = 1;
		for(int j = 1; j <= n; j++){
			//traverse the mpMap to update the unique gcd() values for the case where the right boundry of the subsequence is j.

			for(it = myMap.begin(); it!= myMap.end(); it++) {
				// if the value of gcd() with dat[j] does not change, we do nothing
				// if the value changes, it means the value decreases. Thus, we need to update the vlaue and delete the original value.
				if(gcd(it->first, dat[j]) != it->first) {
					if(myMap[gcd(it->first, dat[j])] == 0) {
						myMap[gcd(it->first, dat[j])] = it->second;

					}
					it2 = it++;
					myMap.erase(it2, it);
					it--;
				}
			}
			// for the element dat[j], the gcd() value is itself. However, this value may also already exist in the myMap.
			if(myMap[dat[j]] == 0) {
				myMap[dat[j]] = j;
			}
			//traverse the myMap to find the optimal solution.
			for(it = myMap.begin(); it!=myMap.end(); it++){
				if(it->first *(j-it->second+1) > res) {
					res = it->first * (j- it->second + 1);
					//left = it->second;
					//right = j;
				}
			}
		}
		cout << res << endl;
		//cout << left << " " << right << endl;
	}
	return 0;
}
