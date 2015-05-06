#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;
int a[50];

int main(){
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int test=1; test<=T; test++){
        int N, M, K;
        scanf("%d%d%d", &N, &M, &K);
        memset(a, -1, sizeof(a));
        int i;
        for(i=0; i<N; i++){
            a[i] = 0;
        }
        for(i=N; i<N+M; i++){
            a[i] = 1;
        }
        int count = 0;
        bool flag = false;
        do{
            if(++count == K){
                for(int j=0; j<N+M; j++){
                    printf("%d", a[j]);
                }
                printf("\n");
                flag = true;
            }
        }while(next_permutation(a, a+M+N));

        if(!flag) printf("Impossible\n");
    }

    return 0;
}
