#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
//    freopen("../in.txt", "r", stdin);
    int n;
    string str;
    cin >> n >> str;
    int len = str.length(), sit = 0, res = 0;
    for(int i=0; i<len; i++){
        if(str[i] == 'x') sit++;
    }
    if(sit >= n/2){
        res = sit - n/2;
        for(int i=0; i<n && sit>n/2; i++){
            if(str[i] == 'x') {
                str[i] = 'X';
                sit--;
            }
        }
    }
    else{
        res = n/2 - sit;
        for(int i=0; i<n && sit<n/2; i++){
            if(str[i] =='X') {
                str[i] = 'x';
                sit++;
            }
        }
    }
    cout << res << endl;
    cout <<str << endl;
    return 0;
}
