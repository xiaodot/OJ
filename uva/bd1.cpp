#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string>

using namespace std;


int main(){
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    getchar();
    for(int test=1; test<=T; test++){

        int res = 0;
        string str;
        getline(cin, str);
        int len = str.length();
        if(len == 0) {
            printf("0\n");
            continue;
        }
        char pre_c, c = str[0];
        int cnt;
        if(isupper(c)){
            cnt = 2;
            pre_c = tolower(c);
        }
        else{
            cnt = 1;
            pre_c = c;
        }
        for(int i=1; i<len; i++){
            c = str[i];
            if(tolower(c) != pre_c){
                res += cnt*cnt*(pre_c-'a'+1);
                if(isupper(c)){
                    pre_c = tolower(c);
                    cnt = 2;
                }
                else{
                    pre_c = c;
                    cnt = 1;
                }
            }
            else{
                if(isupper(c)){
//                    pre_c = lower(c);
                    cnt += 2;
                }
                else{
//                    pre_c = c;
                    cnt += 1;
                }
            }

        }

        res += cnt*cnt*(pre_c-'a'+1);
        printf("%d\n", res);
    }
    return 0;
}
//int main(){
//    freopen("input.txt", "r", stdin);
//    int T;
//    cin >> T;
//    getchar();
//    for(int test=1; test<=T; test++){
//        char c, pre_c;
//        int cnt = 0;
//        int res = 0;
//        c = getchar();
//        if(c == '\n' || c == EOF) {
//            printf("%d\n", 0);
//            continue;
//        }
//
//        if(isupper(c)) {
//            cnt = 2;
//            c = tolower(c);
//        }
//        else cnt = 1;
//        pre_c = c;
//
//        while((c=getchar()) != '\n' && c != EOF){
//            if(tolower(c) != pre_c){
//                res = res + cnt*cnt*(pre_c-'a'+1);
//
//                if(isupper(c)){
//                    pre_c = tolower(c);
//                    cnt = 2;
//                }
//                else{
//                    pre_c = c;
//                    cnt = 1;
//                }
//            }
//            else{
//                if(isupper(c)){
//                    pre_c = tolower(c);
//                    cnt += 2;
//                }
//                else{
//                    pre_c = c;
//                    cnt += 1;
//                }
//            }
//
//        }
//        res = res + cnt*cnt*(pre_c-'a'+1);
//
//        printf("%d\n", res);
//
//    }
//    return 0;
//}
