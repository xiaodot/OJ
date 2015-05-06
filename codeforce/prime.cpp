#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <time.h>
#include <math.h>

using namespace std;

int dat[100001];
int main(){
    int n;
    clock_t start, finish;
    cin >> n;
    start = clock();
    memset(dat, 1, sizeof(dat));
    fill(dat, dat+100001, 1);
    for(int i=2; i<=sqrt(n); i++){
        if(dat[i]){
            for(int j=2*i; j<n; j+=i) dat[j] = 0;
        }
    }
    int cnt = 0;
    for(int i=2; i<=n; i++){
        if(dat[i]) {
//            cout << i << " ";
            cnt++;
        }
    }
    cout << endl << cnt;
    finish = clock();
    cout << endl << (double)(finish-start);
    return 0;
}
