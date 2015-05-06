#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

string str1, str2, str3;

bool dfs(int i, int j, int k){
    if(k == str3.length()) return true;
    if(i + j >= str1.length() + str2.length()) return false;

    if(str3[k] == str1[i]) {
        bool judge = dfs(i+1, j, k+1);
        if(judge) return true;
    }
    if(str3[k] == str2[j]) return dfs(i, j+1, k+1);
    return false;

}

int main(){
    freopen("../in.txt", "r", stdin);
//    string str1, str2, str3;
    while(cin >> str1 >> str2 >> str3){
        if(dfs(0, 0, 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
