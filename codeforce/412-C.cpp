#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
//    freopen("../in.txt", "r", stdin);
    int n, len, p=0;
    string str;
    cin >> n;
    cin >> str;
    getchar();
    len = str.length();
    for(int i=0; i<len; i++){
        if(str[i] == '?') str[i] = 0;
    }
    for(int p=1; p<n; p++){
        for(int i=0; i<len; i++){
            char c = getchar();
            if(c == '?') continue;
            if(c != str[i] && str[i] != 0) str[i] = '?';
            else str[i] = c;
        }
        getchar();
    }
    for(int i=0; i<len; i++){
        if(str[i]==0) {
            cout << 'x';
        }
        else {
            cout << str[i];
        }
    }
    return 0;
}
