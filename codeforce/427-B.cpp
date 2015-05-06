#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

int main(){
//    freopen("../in.txt", "r", stdin);
    int n, t, c;
    cin >> n >> t >> c;
    int num = 0, res = 0;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        if(temp > t){
            res += num-c+1 > 0? num-c+1: 0;
            num = 0;
        }
        else num++;
    }
    res += num-c+1 > 0? num-c+1: 0;
    cout << res << endl;
    return 0;
}
