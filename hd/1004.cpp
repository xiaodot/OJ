#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <cstring>

using namespace std;

int main(){
    freopen("../in.txt", "r", stdin);
    map<string, int> m;
    int n;
    cin >> n;
    while(n!=0){
        m.clear();
        int max_ = -1;
        string color;
        for(int i=0; i<n; i++){
            string str;
            cin >> str;
            if(m.count(str) > 0) m[str]++;
            else m[str] = 0;
            if(max_<m[str]){
                color = str;
                max_ = m[str];
            }
        }
        cout << color << endl;
        cin >> n;
    }
    return 0;
}
