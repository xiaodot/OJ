#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stack>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<string, string> e_type;


int main(){
    freopen("./input.txt", "r", stdin);

    int x, y, z;
    cin >> x >> y >> z;
    getchar();
//    string str;
//    cin >> str;
//    int len = str.length();

    int res = 0;

    map<char, int> cnt;

    cnt['R'] = 0;
    cnt['Y'] = 0;
    cnt['B'] = 0;

    int diff[3], data[3];
    diff[0] = x;
    diff[1] = y;
    diff[2] = z;
    sort(diff, diff+3);

    char c;
    while((c=getchar())!=EOF){
        cnt[c]++;
        res = max(res, cnt['R'] + cnt['Y'] + cnt['B']);
        data[0] = abs(cnt['R'] - cnt['Y']);
        data[1] = abs(cnt['Y'] - cnt['B']);
        data[2] = abs(cnt['B'] - cnt['R']);
        sort(data, data+3);

        if(data[2] == diff[2] && data[1] == diff[1] && data[0] == diff[0]){
            cnt['R'] = 0;
            cnt['Y'] = 0;
            cnt['B'] = 0;
        }
    }
    cout << res << endl;

    return 0;
}
