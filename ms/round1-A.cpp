#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    istringstream iss;
    int T;
    scanf("%d", &T);
    int L;
    int count1[10000], count2[10000];
    char ch1[10000], ch2[10000];
    string str1, str2;
    for(int test=1; test<=T; test++){
        scanf("%d", &L);
        getline(cin, str1);
        getline(cin, str2);
        iss.str(str1);

        int i=0;
//        while(scanf("%d%c", &count1[i], &ch1[i]) != EOF);
        int sum = 0, temp;
        char c;
        bool flag = true;
        iss >> temp >> c;
        while(temp){
//            sum += temp;
//            iss >> temp  >> c;
            cout << temp << " " << c << endl;
            temp = 0;
            cin >> temp >> c;
        }
//        cout << sum << endl;
    }
    return 0;
}
