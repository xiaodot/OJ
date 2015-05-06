#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main(){
//    freopen("../in.txt", "r", stdin);
    int n, s;
    cin >> n >> s;
    int sum = 0, maxi = 0;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        maxi = max(maxi, temp);
        sum += temp;
    }
    sum = sum - maxi;
    if(sum > s) cout << "NO" << endl;
    else cout << "YES";
    return 0;
}
