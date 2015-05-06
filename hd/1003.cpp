#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    freopen("../in.txt", "r", stdin);
    int T;
    cin >> T;
    for(int test=1; test<=T; test++){
        int n, l, l_final, r, dat, sum, res;
        sum = 0;
        res = -1001;
        cin >> n;
        l = l_final = 1;
        r = 0;
        for(int i=1; i<=n; i++){
            cin >> dat;
            sum += dat;
            if(sum > res) {
                l_final = l;
                r = i;
                res = sum;
            }
            if(sum < 0){
                l = i+1;
                sum = 0;
            }
        }
        cout << "Case " << test << ":" << endl;
        cout << res << " " << l_final << " " << r << endl;
        if(test < T) cout << endl;
    }
}

