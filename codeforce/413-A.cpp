#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    freopen("../in.txt", "r", stdin);
    int n, m, mini, maxi;
    cin >> n >> m >> mini >> maxi;
    bool flag = true, maxi_flag = false, mini_flag = false;

    for(int i=0; i<m; i++){
        int r;
        cin >> r;
        if(r<mini || r>maxi) {
            flag = false;
            cout << "Incorrect";
            break;
        }
        if(r == mini) mini_flag = true;
        if(r == maxi) maxi_flag = true;
    }
    if(flag) {
        int j = mini_flag? 1 : 0 + maxi_flag? 1:0;
        if(n-m >= 2 - j) cout << "Correct";
        else cout << "Incorrect";
    }
    return 0;
}
