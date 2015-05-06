#include <iostream>
#include <stdio.h>

#define INF 2000000000

using namespace std;

int main(){
    freopen("C-large-practice.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    for(int test=1; test<=T; test++){
        int N, M, K;
        cin >> N >> M >> K;
        int res = INF;
        for(int x=1; x+2<=N; x++){
            for(int y=1; y+2<=M; y++){
                if((2*x + 2*y + x*y) <= K) res = min(res, K-x*y);
                else {
                    if(x>1 && y>1){
                        int m = max(x, y);
                        for(int i=1; i<m; i++){
                            if(2*x+2*y+x*y-i-1<=K)  res = min(res, K-x*y+i);
                        }
                    }
                }
            }
        }
        if(K<=4 || N<=2 || M<=2) res = K;
        cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}
