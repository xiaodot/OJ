#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stack>
#include <sstream>
#include <map>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int main(){
    freopen("./input.txt", "r", stdin);
    int T;
    cin >> T;
    getchar();
    int data[3][3];

    for(int test=0; test<T; test++){
        char c;
        int x = 0, o = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
               c = getchar();
               if(c == '_') {
                    data[i][j] = 0;
               }
               else if(c == 'O') {
                    data[i][j] = -1;
                    o++;
               }
               else {
                    data[i][j] = 1;
                    x++;
               }
            }
            getchar();
        }
        getchar();

        int sum[8];
        memset(sum, 0, sizeof(sum));

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                sum[i] += data[i][j];
            }
        }
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                sum[i+3] += data[j][i];
            }
        }
        for(int i=0; i<3; i++){
           sum[6] += data[i][i];
           sum[7] += data[i][2-i];
        }


        int cnt_x = 0, cnt_o = 0, next_x = 0, next_o = 0;
        for(int i=0; i<8; i++){
            if(sum[i] == 3){
                cnt_x++;
            }
            else if(sum[i] == -3) {
                cnt_o++;
            }
            else if(sum[i] == 2){
                next_x++;
            }
            else if(sum[i] == -2){
                next_o++;
            }
        }

        if(x!=o && x!=o+1 || cnt_x >=1 && cnt_o >= 1 || cnt_x == 1 && x!=o+1 || cnt_o==1 && x!=o) {
            cout << "Invalid" << endl;
            continue;
        }

        if(cnt_x >= 1 && cnt_o == 0){
            cout << "X win" << endl;
            continue;
        }

        if(cnt_o >= 1 && cnt_x == 0){
            cout << "O win" << endl;
            continue;
        }

        if(x + o == 9){
            cout << "Draw" << endl;
            continue;
        }
        else if(x == o && next_x > 0 || x == o+1 && next_o > 0){
            cout << "Next win" << endl;
            continue;
        }
        else cout << "Next cannot win" << endl;
    }
    return 0;
}





