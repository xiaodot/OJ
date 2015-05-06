#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int main(){
//    freopen("in.txt", "r", stdin);
    int n, k;
    string str, s;
    scanf("%d %d\n", &n, &k);
    getline(cin, str);
    int len = str.length();
    if(len-k >= k-1){
        for(int i=k; i>1; i--){
            printf("LEFT\n");
        }
        for(int i=0; i<len; i++){
            printf("PRINT %c\n", str[i]);
            if(i!=len-1) printf("RIGHT\n");
        }
    }
    else{
        for(int i=1; i<=len-k; i++){
            printf("RIGHT\n");
        }
        for(int i=len-1; i>=0; i--){
            printf("PRINT %c\n", str[i]);
            if(i!=0) printf("LEFT\n");
        }
    }
    return 0;
}
