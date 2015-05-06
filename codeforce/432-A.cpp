#include <iostream>
#include <stdio.h>

using namespace std;

//int dat[2000];
int main(){
//    freopen("../in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int total = 0 ;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        if(temp + k <= 5) total++;
    }
    cout << total/3;
    return 0;
}
