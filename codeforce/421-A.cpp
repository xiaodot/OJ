#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int dat[101], temp;
    memset(dat, 0, sizeof(dat));
    for(int i=0; i<a; i++){
        cin >> temp;
        dat[temp] = 1;
    }
    for(int i=1; i<=n; i++){
        if(dat[i] == 0) cout << 2 << " ";
        else cout << 1 << " ";
    }
    return 0;
}
