#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
    string str;
    int cnt = 0;
    while(cin >> str){
        int len = str.length();
        if(str == "<br>"){
            cout << endl;
            cnt = 0;
        }
        else if(str == "<hr>"){
            if(cnt > 0){
                cout << endl;
            }
            for(int i=0; i<80; i++){
                cout << "-";
            }
            cout << endl;
            cnt = 0;

        }
        else if(cnt + len + 1 <= 80) {
            if(cnt == 0){
                cout << str;
                cnt += len;
            }
            else{
                cout << ' ' << str;
                cnt += len+1;
            }
        }
        else {
            cout << endl << str;
            cnt = len;
        }
    }
    cout << endl;
    return 0;
}
