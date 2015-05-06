#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#define PI 3.1415926

using namespace std;
int gcd(int a, int b){
	return b? gcd(b, a%b): a;
}
void exgcd(int a, int b, int &x, int &y){
	if(!b) {
		x = 1, y = 0;
	}
	else{
		exgcd(b, a%b, y, x);
		y -= x*(a/b);
	}
}
int res[10];
void calc(int n){
	int remain, n1 = n; 
	int order = 1;
	while(n/order>0){
		order *= 10;
		remain = n%order;
		n1 = n/order;
		int digit = remain*10/order;
		for(int i=0; i<10; i++){
			if(i>0) {
				res[i] += n1*order/10;
			}
			else {
				if(n1>0) res[i] += (n1-1)*order/10 +1; //the special feature for digit 0
				//+1 means the **00 should be counted
			}
			

			if(n1>0){
				if(i<digit && i>0) {
					res[i] += order/10;
				}
				if(i==0 && i!=digit){
					res[i] += order/10 - 1;
				}
				if(i==digit){
					res[i] += remain%(order/10) +1;
					if(digit == 0){
						res[i]--;
					}
				}

			}
			else{
				if(i>0 && i<digit) {
					res[i] += order/10;
				}
				if(i==digit){
					res[i] += remain%(order/10) +1;
				}
			}
			
		}
		//res[0]--;

	}
	//res[0]--;
}
int main(){
	freopen("in.txt", "r", stdin);
	int a,b; 
	int res1[10];
	while(cin >> a >> b){
		if(a==0 && b==0) break;
		int c;
		if(a > b) {
			c = a;
			a = b; 
			b = c;
		}
		memset(res, 0, sizeof(res));
		calc(b);
		memset(res1, 0, sizeof(res1));
		for(int i = 0; i<10; i++){
			res1[i] = res[i];
		}
		//memcpy(res1, res, sizeof(res));
		memset(res, 0, sizeof(res));
		calc(a-1);
		for(int i=0; i<10; i++){
			//printf("Digit %d: %d\n", i, res1[i] - res[i]);
			cout << res1[i] - res[i];
			if(i<9) cout << " " ;

		}
		cout << endl;
	}
	return 0;
}