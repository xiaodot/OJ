#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for(int test=1; test <= T; test++){
        int n;
        cin >> n;
        int data;
        int pre_data = 0;
        int res = 0;
        for(int i=0; i<n; i++){
            cin >> data;
            res += abs(data-pre_data)*2;
            pre_data = data;
        }
        res += abs(pre_data - 0)*2;
        printf("%d", res);
        if(test < T) printf("\n");
    }

    return 0;
}
