#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

int main(){
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    char dat1[150][40], dat2[150][40];
    for(int test=1; test<=T; test++){
        int N, L, res=0;
        cin >> N >> L;
        getchar();
        int num1[40], num2[40];
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        for(int i=0; i<N; i++){
            for(int j=0; j<L; j++){
                dat1[i][j] = getchar();
                if(dat1[i][j] == '0') num1[j]++;
            }
            getchar();
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<L; j++){
                dat2[i][j] = getchar();
                if(dat2[i][j] == '0') num2[j]++;
            }
            getchar();
        }
        for(int j=0; j<L; j++){
            if(num1[j] == num2[j]) {
                continue;
            }
            else if(num1[j] + num2[j] == N){
                res++;
                for(int i=0; i<N; i++){
                    dat1[i][j]  = 1 - dat1[i][j] + 96;
                }
            }
            else{
                res = -1;
                break;
            }
        }
        if(res != -1){
            cout << res << endl;
            for(int i=0; i<N; i++){
                for(int j=0; j<L; j++){
                    cout << dat1[i][j];
                }
                cout << " ";
            }
            cout << endl;
            for(int i=0; i<N; i++){
                for(int j=0; j<L; j++){
                    cout << dat2[i][j];
                }
                cout << " ";
            }
            cout << endl;

            for(int m=0; m<L; m++){
                if(num1[m] == num2[m]){
                    //step1
                    int num = 0;
                    for(int i=0; i<N; i++){
                        bool f = false;
                        for(int k=0; k<N; k++){
                            bool flag = true;
                            for(int j=0; j<L; j++){
        //                        if((num1[j] == num2[j]) && (num1[j]+num2[j] == N)) continue;
                                if(dat1[i][j] != dat2[k][j]){
                                    flag = false;
                                    break;
                                }
                            }
                            if(flag) {
                                num++;
                                f = true;
                                break;
                            }
                        }
                        if(!f){
                            for(int i=0; i<N; i++){
                                dat1[i][m]  = 1 - dat1[i][m] + 96;
                            }
                        }
                    }
                    //step2;
                }
            }

        }
        if(res == -1){
            cout << "Case #" << test << ": " << "NOT POSSIBLE" << endl;
        }
        else
            cout << "Case #" << test << ": " << res << endl;
    }

    return 0;
}
