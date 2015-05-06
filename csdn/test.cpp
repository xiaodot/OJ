#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <map>
#include <math.h>
#include <vector>
#include <set>

using namespace std;

int main(){
    freopen("../in.txt", "r", stdin);
    int a, b, c, d;
    while(cin >> a >> b >> c >> d){
        int res = 0;
        if(a >= b){
            int i = (a-b)%3;
            int j = (a-b)/3;
            if(i == 0) res = a;
            else if(i == 1){
                if(b+c+j>0) res = a;
                else if(d>=2) res = a + 1;
                else res = -1;
            }
            else {
                if(b+c+j >1) res = a;
                else if(d>=1) res = a;
                else res = -1;
            }
        }
        else{
            if(a+d>=b) res = b;
            else{
                int i = (b-a-d)%3;
                int j = (b-a-d)/3;
                if(i == 0) res = a + d + 2*j;
                else if(i == 1){
                    if(a+2*d+c+j > 1) res = a + d + 2*j + 2;
                    else res = -1;
                }
                else{
                    res = a + d + 2*j + 2;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
