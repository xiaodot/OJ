#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    freopen("../in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int dat[100][100];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> dat[i][j];
        }
    }
    int res = n;
    while(res%2 == 0){
        bool flag = true;
        for(int i=0; i<res/2; i++){
            if(!flag) break;
            for(int j=0; j<m; j++){
                if(dat[i][j] != dat[res - 1 - i][j]) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) res = res/2;
        else break;
    }
    cout << res << endl;
    return 0;
}
