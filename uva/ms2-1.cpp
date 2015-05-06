#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output-1.txt", "w", stdout);

    int T = 999;
//    cin >> T;
//    getchar();
    vector<vector<int> > data = {{0}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, {0, 2, 3, 5, 6, 8, 9}, {3, 6, 9}, {0, 4, 5, 6, 7, 8, 9}, {0, 5, 6, 8, 9}, {6, 9}, {0, 7, 8, 9}, {0, 8, 9}, {9}};

    for(int test=1; test<=T; test++){


        stringstream ss;
        ss << test;
        string str;
        ss >> str;

//        getline(cin, str);
        int len = str.length();

        string res = "";

        for(int i=0; i<len; i++){
            int cur = str[i]-'0';
            if(cur == 3 || cur == 6 || cur == 9){
//                string tmp = str;
                bool check = true;
                for(int j=i+1; j<len; j++){
                    if(str[j] == str[i]){
                        continue;
                    }
                    else if(str[j] > str[i]){
                        check = true;
                        break;
                    }
                    else if(str[j] < str[i]){
                        check = false;
                        break;
                    }
                }
//                cout << "check: " << check << endl;
                if(check) {
                    res += cur+'0';
                    if(i+1<len) {

                        int k = i+1;
                        while(k<len && str[k]==str[i]) {
                            res += str[i];
                            k++;
                        }
                        if(k < len){
                            if(str[k] < '6') res += '3';
                            else if(str[k] < '9') res += '6';
                            else res += '9';
                            k++;
                            for(; k<len; k++){
                                res += '9';
                            }
                        }

                        break;
                    }
                }
                else{
                    str[i] = str[i] - 1;
                    res += str[i];
                    if(i+1<len) str[i+1] = '9';
                }
                continue;
            }
            res += cur+'0';

            if(i==len-1) continue;

            vector<int> & elem = data[cur];
            int index = 0;
            int val = str[i+1]-'0';
            while(index<elem.size() && elem[index]<=val) index++;

            str[i+1] = elem[index-1]+'0';
            if((str[i+1]-'0') < val && (i+2 < len)) str[i+2] = '9';
        }
        cout << res << endl;

    }
    return 0;
}
