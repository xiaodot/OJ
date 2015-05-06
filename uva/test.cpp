#include <iostream>
#include <bitset>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <limits.h>
#include <cmath>

using namespace std;

bitset<INT_MAX/10> b;

class Solution{
public:
    int CountPrimes(int n){
        if(n <= 2) return 0;

        b.set();
        b.reset(0);
        b.reset(1);
        int res = n - 2;
        int mid = sqrt(n) + 1;
        for(int i=2; i<=mid; i++) if(b.test(i)){
            for(int j=2*i; j<n; j+=i) if(b.test(j)){
                b.reset(j);
                res--;
            }
        }
        return res;
//        return b.count();
    }
};

int main(){
    bitset<32> b(INT_MAX);
    cout << INT_MAX << endl;
    cout << b << endl;
    cout << b.test(0) << b.test(31) << endl;
    cout << ~0U << endl;
    return 0;
}
