#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    double res = 0;
    double month;
    while(cin >> month){
        res += month;
    }
    res = res/12;
    printf("$%.2f", res);
}
