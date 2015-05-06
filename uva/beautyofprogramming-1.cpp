#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stdio.h>
#include <algorithm>

using namespace std;
const long long mod = 1<<64;

typedef pair<int, int> P;

int factors[100000];


int main(){
    freopen("../in.txt", "r", stdin);
    int T;
    cin >> T;

    factors[0] = 1;
    factors[1] = 1;
    factors[2] = 2;
    factors[3] = 6;
    factors[4] = 24;

    for(int test=1; test<=T; test++){
        int n;
        cin >> n;
        vector<int> data(n);
        for(int i=0; i<n; i++){
            string str;
            cin >> str;
            if(str[0] >= '2' && str[0] <= '9') data[i] = str[0] - '0';
            else {
                switch(str[0]){
                case 'A':
                    data[i] = 1;
                    break;
                case 'T':
                    data[i] = 10;
                    break;
                case 'J':
                    data[i] = 11;
                    break;
                case 'Q':
                    data[i] = 12;
                    break;
                case 'K':
                    data[i] = 13;
                    break;
                }
            }
        }

        sort(data.begin(), data.end());

        int factor = 1;
        int cnt = 1, pre = data[0];
        for(int i=1; i<data.size(); i++){
            if(data[i] != pre){
                factor *= factors[cnt];
                cnt = 1;
            }
            else cnt++;
            pre = data[i];
        }
        factor *= factors[cnt];

        long long res = 0;
        do{
            bool flag = true;
            for(int i=0; i<data.size()-1; i++){
                if(data[i] == data[i+1]) {
                    flag = false;
                    break;
                }
            }
            if(flag) res++;
        }
        while(next_permutation(data.begin(), data.end()));

        cout << "Case #" << test << ": " << res*factor  << endl;
    }

    return 0;
}
