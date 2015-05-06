#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
    freopen("../in.txt", "r", stdin);
    string str;
    cin >> str;
    int len = str.length();
    for(int i=0; i<len; i++){
        switch (str[i]){
        case 'A':
        case 'H':
        case 'I':
        case 'M':
        case 'O':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
            continue;
            break;
        default:
            cout << "NO";
            return 0;
        }
    }
    for(int i=0; i<=len/2; i++){
        if(str[i] != str[len-1-i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}
