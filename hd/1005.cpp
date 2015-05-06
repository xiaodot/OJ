#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <cstring>

using namespace std;
int pre1, pre2;

int f(int a, int b, int n){
    if(n==1 || n==2) return 1;
    int res = pre
    return r[n] = (a*f(a, b, n-1) + b*f(a, b, n-2))%7;
}
int main(){
    freopen("../in.txt", "r", stdin);
    int a, b, n;
    cin >> a >> b >> n;
    while(a!=0){
        pre1 = pre2 = 1;
        cout << f(a%7, b%7, n) << endl;
        cin >> a >> b >> n;
    }
    return 0;
}
