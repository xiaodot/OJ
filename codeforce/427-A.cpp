#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
//    freopen("../in.txt", "r", stdin);
    int n;
    cin >> n;
    int police = 0, crime = 0, res = 0;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        if(temp == -1) {
            if(police > 0) {
                police--;
                continue;
            }
            else res++;
        }
        else police += temp;
    }
    cout << res;
    return 0;
}
