#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("../in.txt", "r", stdin);
    int T;
    cin >> T;
    for(int test=1; test<=T; test++){
        string str1, str2;
        vector <char> res;
        cin >> str1 >> str2;
        int len1 = str1.length();
        int len2 = str2.length();
        int carry = 0, i = 0;
        if(len1 >= len2){
            for(; i<len1; i++){
                int temp;
                if(i<len2){
                    temp = str1[len1-1-i] - '0' + str2[len2-1-i] - '0' + carry;
                }
                else{
                    temp = str1[len1-1-i] - '0'  + carry;
                }
                res.push_back(temp % 10 + '0');
                carry = temp/10;
            }
        }
        else{
             for(; i<len2; i++){
                int temp;
                if(i<len1){
                    temp = str1[len1-1-i] - '0' + str2[len2-1-i] - '0' + carry;
                }
                else{
                    temp = str2[len2-1-i] - '0'  + carry;
                }
                res.push_back(temp % 10 + '0');
                carry = temp/10;
            }
        }
        if(carry == 1) res.push_back('1');
        reverse(res.begin(), res.end());
        cout << "Case " << test << ":" << endl;
        cout << str1 << " + " << str2 << " = ";
        for(int i=0; i<res.size(); i++){
            cout << res[i];
        }
        cout << endl;
        if(test < T) cout << endl;
    }

    return 0;
}
